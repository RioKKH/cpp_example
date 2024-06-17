#include <iostream>
#include <vector>

auto for_each = [] (auto first, auto last, auto f)
{
    for (auto iter = first; iter != last; ++iter) {
        f(*iter);
    }
};

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    // 引数を出力する関数
    auto print_value = [] (auto value) { std::cout << value; };
    for_each(std::begin(v), std::end(v), print_value);

    // 引数を2倍して出力する関数
    auto print_twice = [] (auto value) { std::cout << 2 * value; };
    for_each(std::begin(v), std::end(v), print_twice);

    // 引数を出力したあとに改行を出力する関数
    auto print_with_newline = [] (auto value) { std::cout << value << "\n"; };
    for_each(std::begin(v), std::end(v), print_with_newline);
}

