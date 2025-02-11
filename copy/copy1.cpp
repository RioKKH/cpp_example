#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1};

    auto i = std::begin(v);

    // 参照する要素を値として使う
    // イテレータiは*iで参照する要素の値として使うことが出来る
    std::cout << *i << std::endl;

    // 参照する要素に値を代入する
    *i = 2;
    std::cout << *i << std::endl;
}

