#include <iostream>
#include <string>

template <typename T>
T id(T value)
{
    return value;
}

int main()
{
    std::cout << id<int>(1) << std::endl;
    std::cout << id<float>(10.0f) << std::endl;
    std::cout << id<double>(20.0) << std::endl;
    std::cout << id<std::string>("Hello") << std::endl;
}
