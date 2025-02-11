#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    // 要素に1つでも3が含まれているか？
    // true
    bool has_3 = std::any_of(std::begin(v), std::end(v), [](auto x) { return x == 3; });

    // 要素に1つでも10が含まれているか？
    // false
    bool has_10 = std::any_of(std::begin(v), std::end(v), [](auto x) {return x == 10; });
};
