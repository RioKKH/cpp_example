#include <iostream>

int main()
{
    int x = 0;

    // OK
    int &ref = x;
    // OK
    const int &cref = x;
    int const &refc = x;
    std::cout << ref << "," << cref << "," << refc << std::endl;
    ++x;
    std::cout << ref << "," << cref << "," << refc << std::endl;
}
