#include <iostream>

auto print = [](auto first, auto last)
{
    for (auto iter = first; iter != last; ++iter)
    {
        std::cout << *iter << std::endl;
    }
};

// 関数の中でテンプレート引数名を型や値として使える
template<typename T, T N>
T value()
{
    return N;
}

template<typename T, std::size_t N>
struct array
{
    T storage[N];

    T &operator [](std::size_t i)
    {
        return storage[i];
    }
};

int main()
{
    std::cout << value<int, 1>() << std::endl;
    std::cout << value<short, 1>() << std::endl;
    array<int, 5> a = {1, 2, 3, 4, 5};
    std::cout << a[2] << std::endl;
}
