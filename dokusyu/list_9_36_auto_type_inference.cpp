#include <iostream>
#include <string>

// generic lambdas ジェネリックラムダ式
// 引数の型推論をするラムダ式 auto type inference of lambdas
std::string type(int)
{
    return "int";
}

std::string type(const char*)
{
    return "const char*";
}

int main()
{
    auto lambda = [](const auto& value) // valueの型は呼び出し時の引数から推論される
    {
        std::cout << type(value) << std::endl;
    };

    auto check = [](const auto& value)
    {
        std::cout << type(value) << std::endl;
    };

    lambda(42);
    lambda("type deduction");
    check(6);
}
