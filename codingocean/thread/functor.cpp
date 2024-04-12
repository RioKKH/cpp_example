#include <iostream>
#include <thread>

class functor {
public:
    void operator()() {
    // void operator()(int n) {
        int n = 10;
        while (n-- > 0) { std::cout << n << std::endl; }
    }
};

class functor2 {
public:
    void operator()(int n) {
        while (n-- > 0) { std::cout << n << std::endl; }
    }
};

int main() {
    // tという関数宣言になってしまっている
    // これだとこける。tという関数でスレッドを返すよ、
    // という意味になってしまう
    // std::thread t( functor() );

    // 上記を回避するために、functorのインスタンスを作成して
    // それをthreadのインスタンスに渡す
    std::thread t1( (functor()) );
    // functorのインスタンスを作成する。
    functor f;
    std::thread t2(f);

    functor2 f2;
    std::thread t3(f2, 10);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
