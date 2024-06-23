#include <iostream>

template<typename T>
void f(T const &x)
{
    std::cout << x << std::endl;
}

int main()
{
    // 明示的なテンプレート引数の型指定方法
    // Tはint
    f<int>(0);

    // Tはdouble
    // int型0からdouble型0.0への変換が行われる
    f<double>(0);
}
