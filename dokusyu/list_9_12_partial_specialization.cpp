#include <iostream>

// プライマリーテンプレート primary template
template <typename A, typename B, typename C>
struct Tuple
{
    A a;
    B b;
    C c;

    void show() const
    {
        std::cout << '{' << a << ", " << b << ", " << c << '}' << std::endl;
    }
}; 
// 2番目のテンプレートパラメータをvoid 限定した部分特殊化
template <typename A, typename C> // 限定していない部分を埋める為の
                                  // テンプレートパラメータ
struct Tuple<A, void, C> // 限定しなかった部分はテンプレートパラメータを使う
{
    A a;
    C c;

    void show() const
    {
        std::cout << '{' << a << ", " << c << '}' << std::endl;
    }
};

int main()
{
    // 2番目のテンプレートパラメータがvoid なので、部分特殊化が使われる
    Tuple<int, void, float> t = {42, 3.1415};

    t.show();
}
