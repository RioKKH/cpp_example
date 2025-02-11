#include <iostream>

template <typename T>
class S
{
public:
    T x;
    T y;

    // メンバー関数の体語をクラス定義の中で書く場合にはそれほど難しく無い
    void foo()
    {
        std::cout << "menber function defined inside of class definition" << std::endl;
    }

    void bar();

    void show() const
    {
        std::cout << x << " " << y << std::endl;
    }
};

// クラステンプレートSのメンバー関数定義
template <typename T>
void S<T>::bar()
{
    std::cout << "menber function defined outside of class definition" << std::endl;
}

int main()
{
    S<int> sint{1, 2};
    sint.show();
    sint.foo();
    sint.bar();

    S<float> sfloat{1.1f, 2.2f};
    sfloat.show();
    sfloat.foo();
    sfloat.bar();
}
