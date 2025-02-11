#include <iostream>

// プライマリーテンプレート
template <typename A, typename B, typename C>
class X
{
public:
    X() { std::cout << "プライマリーテンプレート" << std::endl; }
};

// 部分特殊化したクラステンプレート
template <typename A, typename B>
class X<A, B, int>
{
public:
    X() { std::cout << "部分特殊化 X<A, B, int>" << std::endl; }
};

int main()
{
    X<void, int, float> vif;
    X<char, int*, int> cipi;
}
