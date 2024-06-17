#include <iostream>

int main(int argc, char const* argv[])
{
    int a = 10;
    int* pA = nullptr;
    int** ppA = nullptr;
    pA = &a;
    ppA = &pA;
    std::cout << **ppA << std::endl;
}
