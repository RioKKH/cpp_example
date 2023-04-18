#include <iostream>

// テンプレートパラメータパックの要素数
template <typename... T>
void count_params(T... args)
{
    std::cout << "テンプレートパラメータパックの要素数は " << sizeof...(T)
        << std::endl;

    std::cout << "関数パラメータパックの要素数は " << sizeof...(args)
        << std::endl;
}

int main()
{
    count_params(0);
    count_params(1, 2, 3);
}
