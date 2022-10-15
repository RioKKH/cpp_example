#include <iostream>
#include <typeinfo>

int main()
{
    auto lambda1 = [](){};
    auto lambda2 = [](){};

    if (typeid(lambda1) != typeid(lambda2))
    {
        std::cout << "ラムダ式は異なる型を持っています" << std::endl;
    }
}
