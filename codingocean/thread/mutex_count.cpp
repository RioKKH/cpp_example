#include <iostream>
#include <thread>
#include <mutex>
using namespace std::chrono_literals;

int cnt = 0;
std::mutex mtx;

void countup() {
    for (int i = 0; i < 1000; ++i) {
        // critical section starts from here
        mtx.lock();
        cnt++;
        mtx.unlock();
        // critical section ends here
        std::this_thread::sleep_for(0s);
    }
}

int main() {
    std::thread th1(countup);
    std::thread th2(countup);
    th1.join();
    th2.join();
    std::cout << "cnt: " << cnt << std::endl;

    return 0;
}
