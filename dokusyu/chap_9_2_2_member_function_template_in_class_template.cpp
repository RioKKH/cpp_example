#include <iostream>
#include <string>

template <typename T>
class S
{
public:
    // クラス定義の中でメンバー関数テンプレートも書いてしまう場合
    template <typename U>
    void foo(U value)
    {
        std::cout << "foo: " << value << std::endl;
    }

    // 宣言と定義を分けて書く場合
    template <typename U>
    void bar(U value);
};

template <typename T>   // クラステンプレートのためのtemplate
template <typename U>   // メンバー関数テンプレートのためのtemplate
void S<T>::bar(U value)
{
    std::cout << "bar: " << value << std::endl;
}

int main()
{
    S<int> s; // 適当にclassの型はintとしておく
    s.foo<int>(1);
    s.bar<std::string>("hello");
}
