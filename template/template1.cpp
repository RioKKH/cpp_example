#include <iostream>

template<typename T>
T twice(T n)
{
    return n * 2;
}

int main()
{
    std::cout << twice(123) << std::endl; // int
    std::cout << twice(1.23) << std::endl; // double
}
