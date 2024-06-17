#include <iostream>

// イテレータを表現するクラス
struct array_iterator
{};

template <typename T, std::size_t>
struct array
{
    // イテレータ型
    using iterator = array_iterator;

    // イテレータを返すメンバー関数
    iterator begin();
    iterator end();

    // その他のメンバー
};

int main()
{
    // std::array<int, 5> a = {1, 2, 3, 4, 5};
    array<int, 5> a = {1, 2, 3, 4, 5};

    auto iter = a.begin();
    int x = *iter; // 1
    *iter = 0;
    // aは{0, 2, 3, 4, 5}
}

