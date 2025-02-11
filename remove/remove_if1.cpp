#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // 偶数の場合true, 奇数の場合falseを返す関数
    auto is_even = [](auto x){ return x%2 == 0; };

    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 偶数を取り除く
    auto last = std::remove_if(std::begin(v), std::end(v), is_even);

    std::for_each(std::begin(v), last, [](auto x){ std::cout << x; });
    // [std::begin(v), last)は{1, 3, 5, 7, 9}
}
