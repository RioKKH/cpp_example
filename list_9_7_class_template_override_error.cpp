#include <iostream>

class Base
{
public:
    virtual void foo(int i)
    {
        std::cout << "Base::foo()" << std::endl;
    }
};

template <typename T>
class Derived : public Base
{
public:
    // Baseのfooをオーバーライド市営るつもりだが、
    // Tに渡されるテンプレート引数によって動作が異なる。
    void foo(T val) override
    {
        std::cout << "Derived::foo()" << std::endl;
    }
};


int main()
{
    Derived<int> di; // fooがオーバーライドされる場合
    di.foo(0);
    // 仮想関数を経由した派生クラスのメンバー呼び出し
    static_cast<Base&>(di).foo(0);

    // エラー。仮想関数の仮引数の型が異なってしまい、
    // オーバーライドが失敗する
    // Derived<float> df;
}
