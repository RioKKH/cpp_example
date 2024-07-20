#include <iostream>

class Adder {
private:
    int base_;

public:
    Adder(int base) : base_(base) {}

    int operator()(int x) const {
        return base_ + x;
    }
};

int main() {
    Adder add5(5);
    // オブジェクトを関数のように使うことができる！
    // --> 関数オブジェクトという！
    std::cout << add5(10) << std::endl; // 出力は15
    return 0;
}
