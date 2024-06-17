#include <iostream>

int main()
{
    // 変数に代入された関数
    auto print = [](auto x) { std::cout << x; };

    // 変数に代入された関数の呼び出し
    print(123);
}
