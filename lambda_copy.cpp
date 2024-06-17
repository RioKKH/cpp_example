#include <iostream>

int main()
{
    int value = 123;

    auto f = [=]() { return value; };

    auto v = f(); // 123
    std::cout << v << std::endl;
};
