#include <iostream>

void throw_error()
{
    throw 0;
}

int main()
{
    std::cout << "before throw" << std::endl;

    try
    {
        throw_error();
        std::cout << "after throw" << std::endl;
    }
    catch (int e)
    {
        std::cout << "Error caught." << std::endl;
    }

    std::cout << "end of program" << std::endl;
}
