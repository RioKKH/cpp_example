#include <iostream>
#include <thread>
#include <mutex>
using namespace std::chrono_literals;

std::mutex mtx;

void dateWithAraragi(std::string name) {
    mtx.lock();
    // critical section from here -------------------
    std::cout << name << " is waiting for Araragi to come." << std::endl;
    std::this_thread::sleep_for(1s);
    std::cout << name << " is dating with Araragi." << std::endl;
    std::this_thread::sleep_for(1s);
    // to here ---------------------------------------
    mtx.unlock();
}

int main() {
    std::thread th1(dateWithAraragi, "Hanegawa");
    std::thread th2(dateWithAraragi, "Hitagi");
    th1.join();
    th2.join();

    return 0;
}
