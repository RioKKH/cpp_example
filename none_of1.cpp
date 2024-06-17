#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    // 値は100か？ 100でなければnone_ofが成り立つのでtrueが返る
    auto is_100 = [](auto x) { return x == 100; };
    bool b = std::none_of(std::begin(v), std::end(v), is_100);
    std::cout << b << std::endl; // 100ではないので1(true)が返る
}
