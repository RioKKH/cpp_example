#include <iostream>

int main()
{
    int x = 0;
    int &ref = x;
    ++ref; // 1
    ++ref; // 2
    std::cout << ref << std::endl;

    const int &const_ref = x;

    // error
    // ++const_ref;

    int a = 0;

    const int &b = a;
    int const &c = a;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    ++a;
    std::cout << "++a" << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    // error
    // int & const d = a;
}
