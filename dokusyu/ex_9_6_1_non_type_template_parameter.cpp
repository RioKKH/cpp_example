#include <iostream>

template <int i>
void show()
{
    std::cout << i << std::endl;
}

int main()
{
    show<42>();
    return 0;
}
