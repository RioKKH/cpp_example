#include <iostream>
#include <string>

template <typename T>
void f(T const &x)
{
    std::cout << x << std::endl;
}

int main()
{
    // テンプレートが使われる時にテンプレート引数に対する具体的な型が決定する
    // Tはint
    f(0);
    // Tはdouble
    f(0.0);
    // Tはstd::string
    f("hello");
}
