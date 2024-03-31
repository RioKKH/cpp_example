#include <iostream>
#include <thread>
using namespace std::chrono_literals;

void dateWithAraragi(std::string name) {
    std::cout << name << " is waiting for Araragi to come." << std::endl;
    std::this_thread::sleep_for(1s);
    std::cout << name << " is dating with Araragi." << std::endl;
    std::this_thread::sleep_for(1s);
}

int main() {
    std::thread th1(dateWithAraragi, "Hanegawa");
    std::thread th2(dateWithAraragi, "Hitagi");
    th1.join();
    th2.join();

    return 0;
}
