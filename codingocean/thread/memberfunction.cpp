#include <iostream>
#include <thread>

class Hoge {
public:
    void func(int n) {
        while (n-- > 0) {
            std::cout << n << std::endl;
        }
    }
};

int main() {
    Hoge h;
    std::thread t(&Hoge::func, &h, 10);
    t.join();

    return 0;
}
    
