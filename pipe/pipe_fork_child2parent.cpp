#include <iostream>
#include <array>
#include <string>
#include <system_error>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

/**
 * @class Pipe
 * @brief パイプを表すクラス
 *
 * RAII (Resource Acquisition is Initialization) を利用して
 * パイプのリソース管理を行う
 */
class Pipe {
private:
    std::array<int, 2> fds;

public:
    Pipe() {
        if (pipe(fds.data()) == -1) {
            throw std::system_error(errno, std::generic_category(), "pipe");
        }
    }

    ~Pipe() {
        close(fds[0]);
        close(fds[1]);
    }
    int read_fd() const { return fds[0]; }
    int write_fd() const { return fds[1]; }
    void close_read() { close(fds[0]); fds[0] = -1; }
    void close_write() { close(fds[1]); fds[1] = -1; }
};

void write_to_pipe(int fd, const std::string& message) {
    if (write(fd, message.c_str(), message.length())
            != static_cast<ssize_t>(message.length())) {
        throw std::system_error(errno, std::generic_category(), "write");
    }
}

std::string read_from_pipe(int fd) {
    std::array<char, 1024> buffer;
    ssize_t n = read(fd, buffer.data(), buffer.size());
    if (n == -1) {
        throw std::system_error(errno, std::generic_category(), "read");
    }
    return std::string(buffer.data(), n);
}

int main() {
    try {
        Pipe pipe;
        pid_t pid = fork();

        if (pid == -1) {
            throw std::system_error(errno, std::generic_category(), "fork");
        }
        else if (pid == 0)
        { // 子プロセス
            pipe.close_read();
            write_to_pipe(pipe.write_fd(), "Hello from child process\n");
        }
        else
        { // 親プロセス
            pipe.close_write();
            std::string message = read_from_pipe(pipe.read_fd());
            std::cout << "Received from child: " << message;

            int status;
            if (waitpid(pid, &status, 0) == -1) 
            {
                throw std::system_error(errno, std::generic_category(), "waitpid");
            }
            if (WIFEXITED(status))
            {
                std::cout << "Child exited with status " << WEXITSTATUS(status) << std::endl;
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}









