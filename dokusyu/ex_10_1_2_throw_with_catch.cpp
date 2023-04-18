#include <iostream>

void throw_error(int e)
{
    throw e;
}

int main()
{
    try
    {
        throw_error(0);
    }
    catch (int e)
    {
        std::cout << "catched." << std::endl;
    }

    return 0;
}
