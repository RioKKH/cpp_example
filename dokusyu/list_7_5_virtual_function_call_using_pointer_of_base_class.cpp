#include <iostream>

class Base
{
public:
    // 継承したクラス側でoverrideする目印としてのvirtual
    virtual void method();
};

void Base::method()
{
    std::cout << "Baseのメンバー関数" << std::endl;
}

class Derived : public Base
{
public:
    // Base::method()をオーバーライド
    // void method();
    void method() override;
};

void Derived::method()
{
    std::cout << "Derivedでオーバーライドしたメンバ−関数" << std::endl;
}

int main()
{
    Derived derived;
    Base& base = derived; // 基底クラスへの参照を取得

    // 基底クラスへの参照経由であっても、
    // 仮想関数はDerivedでオーバーライドしたほうが呼ばれる
    base.method();
}

