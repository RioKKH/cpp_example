#include <iostream>
#include <array>

auto print = [](auto first, auto last)
{
    for (auto iter = first; iter != last; ++iter)
    {
        std::cout << *iter << std::endl;
    }
};

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    // error 配列はコピーできない
    // int b[5] = a;

    std::array<int, 5> c = {1, 2, 3, 4, 5};
    // OK std::arrayはコピーできる
    std::array<int, 5> d = c;
    print(std::begin(c), std::end(c));
    // print(c.begin(), c.end());
}
