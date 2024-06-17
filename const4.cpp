#include <iostream>
#include <vector>

// void f(std::vector<int> const &v) // どちらでも良い。constの文法のややこしいところ
void f(const std::vector<int> &v)
{
    // lvalue referenceにすることで、不要な値のコピーを避けることが出来る。
    // constをつけることで、関数の中でもvが変更されていなことが保証される
    std::cout << v.at(1234);
}

int main()
{
    // 10000個の要素を持つvector
    std::vector<int> v(10000, 2);

    f(v);
}


