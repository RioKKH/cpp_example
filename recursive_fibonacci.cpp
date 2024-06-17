#include "all.h"

int GetFibNumber(int fibIndex)
{
    if (fibIndex < 2) {
        std::cout << "After: " << fibIndex << std::endl;
        return fibIndex;
    } else { // recursion if figIndex >= 2
        std::cout << "Before: " << fibIndex << std::endl;
        return GetFibNumber(fibIndex - 1) + GetFibNumber(fibIndex - 2);
    }
}

int main(int argc, char const* argv[])
{
    std::cout << "Enter 0=based index of desired Fibonacci Number: ";

    int index = 0;
    std::cin >> index;

    std::cout << "Fibonacci number is: " << GetFibNumber(index) << std::endl;
    return 0;
}

