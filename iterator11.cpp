#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> a = {1, 2, 3, 4, 5};

    // iterator
    std::array<int, 5>::iterator iter = a.begin();

    // const_iterator
    std::array<int, 5>::const_iterator const_iter = a.cbegin();

    using Array = std::array<int, 5>;

    // iterator
    Array::iterator i;
    //const iterator
    const Array::iterator c_i;
    // const_iterator
    Array::const_iterator ci;
    // const const_iterator
    const Array::const_iterator c_ci;
}
