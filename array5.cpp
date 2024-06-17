#include <iostream>

template <typename T, std::size_t N>
struct array
{
    T storage[N];

    using reference = T &;
    // std::arrayではconstなreferenceをconst_referenceというネストされた型名にしている
    using const_reference = T const &;

    // 非const版
    reference operator [](std::size_t i)
    {
        return storage[i];
    }

    // const版
    const_reference operator [](std::size_t i) const
    {
        return storage[i];
    }
};
