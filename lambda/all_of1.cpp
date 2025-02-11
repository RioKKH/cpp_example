#include <iostream>
#include <vector>
#include <algorithm>

// 要素が全て偶数課どうかを調べる関数
auto is_all_of_odd = [](auto first, auto last)
{
    return std::all_of(first, last, [](auto value) { return value % 2 == 0; });
};

// 要素が全て100以下かどうかを調べる関数
auto is_all_of_le_100 = [](auto first, auto last)
{
    return std::all_of(first, last, [](auto value) { return value <= 100; });
};


int main()
{
    // 空のvector
    std::vector<int> v;
    bool b = std::all_of(std::begin(v), std::end(v), [](auto value) {return false;});

    std::vector<int> v1 = {1, 2, 3, 4, 5};
    bool b1 = is_all_of_odd(v1.begin(), v1.end());
    std::cout << "b1: " << b1 << std::endl; // 0 -> false

    std::vector<double> v2 = {1.0, 50.0, 100.0, 200.0, 300.0};
    bool b2 = is_all_of_le_100(v2.begin(), v2.end());
    std::cout << "b2: " << b2 << std::endl; // 0 -> false

    std::vector<int> v3 = {2, 4, 6};
    bool b3 = is_all_of_odd(v3.begin(), v3.end());
    std::cout << "b3: " << b3 << std::endl; // 1 -> true

    std::vector<double> v4 = {1.0, 25.0, 50.0, 75.0};
    bool b4 = is_all_of_le_100(v4.begin(), v4.end());
    std::cout << "b4: " << b4 << std::endl; // 1 -> true


}
