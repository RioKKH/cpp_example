#include <iostream>

int main()
{
    int value = 123;

    auto f = [&]() { ++value; };

    f();
    std::cout << value << std::endl; // 124
};
