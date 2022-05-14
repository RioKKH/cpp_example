#include <iostream>

// クラステンプレートのメンバー関数として関数テンプレートを定義する
// 関数テンプレートの定義はクラステンプレートの外で行う
template <typename T>
class A
{
public:
    template <typename U>
    void show(U u);
};

template <typename T>
template <typename U>
void A<T>::show(U u)
{
    std::cout << u << std::endl;
}

int main()
{
    A<int> a;
    a.show(42);

    A<float> aa;
    aa.show(42);

    A<int> aaa;
    aaa.show(3.3f);

    return 0;
}
