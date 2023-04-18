#include <iostream>

template <typename T>
void show_value(T value)
{
    std::cout << value << std::endl;
}

int main()
{
    show_value(0);
    show_value(42.195f);
}   
