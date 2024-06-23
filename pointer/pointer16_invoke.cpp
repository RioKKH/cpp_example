#include <iostream>
#include <functional>

struct C
{
    int data {};
};

int main()
{
    auto data_ptr = &C::data;

    C object;

    // どちらも同じ意味
    object.*data_ptr = 123;
    std::invoke(data_ptr, object) = 123; // C++17
}



