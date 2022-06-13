#include <iostream>

int main()
{
    int *ptr = new int(10);

    for (int i = 0; i < 10; ++i)
    {
        *ptr += i;
    }

    std::cout << "ptr = " << *ptr << std::endl;

    delete ptr;

    return 0;
}
