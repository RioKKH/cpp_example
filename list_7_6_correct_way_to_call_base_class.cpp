#include <iostream>

class Base
{
public:
    virtual void method();
};

void Base::method()
{
    // 基底クラスでの実装：派生クラスから呼び出される事を期待する
    std::cout << "Base::method()" << std::endl;
}


class Derived : public Base
{
public:
    void method() override;
};

void Derived::method()
{
    std::cout << "Derived:method()" << std::endl;
    // 再帰呼び出し recursive call を回避するための書き方
    Base::method(); // どのクラスのメンバーかを指定しての呼び出し
    this->Base::method(); // このように書くことも可能
}

int main()
{
    Derived derived;
    derived.method(); // オーバーライドしたメンバー関数の呼び出し

    return 0;
}
