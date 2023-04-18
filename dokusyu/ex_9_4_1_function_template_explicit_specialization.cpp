#include <iostream>
#include <string>

template <typename T>
void show(T a)
{
    std::cout << a << std::endl;
}

template <>
void show(std::string s)
{
    std::cout << "specialized template: " << s << std::endl;
}

int main()
{
    show(5);
    show("Hello");
}
