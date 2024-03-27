#include <iostream>
#include <thread>

int main() {
    // こうもかけるし
    auto func = [](int n) { 
        while (n-- > 0) {
            std::cout << n << std::endl;
        }
    };
    std::thread t(func, 10);

    // こうもかける
    // std::thread t([](int n) { while (n-- > 0) { std::cout << n << std::endl; }}, 10);
    t.join();

    return 0;
}
