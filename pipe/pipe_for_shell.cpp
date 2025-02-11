#include <iostream>
#include <stdexcept> // std::runtime_error
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <array>

class Pipe {
private:
    std::array<int, 2> fds;
public:
    Pipe() {
        if (pipe(fds.data()) == -1) {
                throw std::runtime_error(std::string("pipe failed: ") + std::strerror(errno));
        }
    }
    ~Pipe() {
        close(fds[0]);
        close(fds[1]);
    }
    // getter
    int read_fd() const { return fds[0]; }
    int write_fd() const { return fds[1]; }

    void close_read() { close(fds[0]); fds[0] = -1; }
    void close_write() { close(fds[1]); fds[1] = -1; }
};

void redirect_and_exec(int old_fd, int new_fd, const char* command) {
    if (dup2(old_fd, new_fd) == -1) {
        throw std::runtime_error(std::string("dup2 failed: ") + std::strerror(errno));
    }
    if (execlp(command, command, nullptr) == -1) {
        throw std::runtime_error(std::string("execlp failed: ") + std::strerror(errno));
    }
}

int main(int argc, char *argv[]) {
    try {
        if (argc < 3) {
            throw std::runtime_error(std::string("Usage: ") + argv[0] + " command1 command2");
        }

        Pipe pipe;
        pid_t pid = fork();

        if (pid == -1) {
            throw std::runtime_error(std::string("fork failed: ") + std::strerror(errno));
        } else if (pid == 0) { // 子プロセス
            pipe.close_read();
            redirect_and_exec(pipe.write_fd(), STDOUT_FILENO, argv[1]);
        } else { // 親プロセス
            pipe.close_write();
            redirect_and_exec(pipe.read_fd(), STDIN_FILENO, argv[2]);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

