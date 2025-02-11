#include <iostream>
#include <type_traits>

// c++17
template <typename T>
void foo(T v)
{
    static_assert(std::is_integral<T>::value);
}

int main()
{
    foo<int>(5);
    // foo<float>(5.0);
}
