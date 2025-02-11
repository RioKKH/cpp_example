#include <iostream>

int main(int argc, char const* argv[])
{
    int a = 10;
    int *pA = nullptr;
    pA = &a; // アドレス演算子
    // pA = addressof(a) // This also works!
    *pA = 20; // 関節演算子・参照剥がし演算子
    std::cout << a << std::endl;
}
