#include <iostream>
#include <array>

// std::begin(), std::end()が何をしているのか、実装を確認する
namespace stdtest
{
    template <typename C>
    auto begin(C &c)
    {
        return c.begin();
    }

    template <typename C>
    auto begin(C const &c)
    {
        return c.begin();
    }

    template <typename C>
    auto end(C &c)
    {
        return c.end();
    }

    template <typename C>
    auto end(C const &c)
    {
        return c.end();
    }
};

int main()
{
    std::array<int, 5> a = {1, 2, 3, 4, 5};

    auto iter = a.begin();
    std::cout << *iter << std::endl; // 1
    ++iter;
    std::cout << *iter << std::endl; // 2
}


