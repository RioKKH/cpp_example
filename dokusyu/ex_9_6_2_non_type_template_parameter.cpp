#include <iostream>

template <auto value>
void show()
{
    std::cout << value << std::endl;
}

int main()
{
    show<42>();
    show<1.23f>();

    return 0;
}

