#include <iostream>
#include <vector>
#include <algorithm>

// サイズを求める関数の実装
auto distance = [](auto first, auto last)
{
    return last - first;
};

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    // 最初の要素
    auto first = std::begin(v);

    // 最後の1つ次の要素
    auto last = std::end(v);

    // 要素数: 5
    auto size = std::distance(first, last);

    // 最初の次の要素
    auto next = first + 1;

    // 4
    auto size_from_next = std::distance(first + 1, last);

    std::cout << *first << std::endl;
    std::cout << *last  << std::endl;
    std::cout << size << std::endl;
    std::cout << size_from_next << std::endl;
}
