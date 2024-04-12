#include <iostream>
#include <thread>

void func(int n) {
    while (n-- > 0) {
        std::cout << n << std::endl;
    }
}

int main() {
    std::thread t(func, 10);
    t.join();

    return 0;
}
