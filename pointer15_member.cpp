#include <iostream>

struct C
{
    int data {};
};

int main()
{
    auto data_ptr = &C::data;

    C object;
    auto c_ptr = &object;

    c_ptr->*data_ptr = 123;
    // (*(c_ptr)).*data_ptr = 123; // これも同じこと
}
