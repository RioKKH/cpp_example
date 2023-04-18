#include <iostream>

class Base
{
public:
    void method_Base();
};

void Base::method_Base()
{
    std::cout << "Base::method_Base()" << std::endl;
}

class Derived : public Base
{
public:
    void method_Derived();
};

void Derived::method_Derived()
{
    std::cout << "Derived::method_Derived()" << std::endl;
}

int main()
{
    Derived derived;

    // OK. DerivedはBaseのメンバー関数を継承しているので呼び出せる
    derived.method_Base();

    // OK. もちろんDerivedのメンバー関数も呼び出せる
    derived.method_Derived();

    // 基底クラスへの参照は派生クラスからも作れる
    Base& base = derived;

    // OK. Baseのメンバー関数へはBaseの参照からたどることが出来る
    base.method_Base();
    // baseはあくまで基底クラスへの参照なので
    // baseからDerivedのメンバー関数を呼び出す事は出来ない
    // 参照先の実際のインスタンスがDerivedであってもBaseの参照からは辿れない
    // base.method_Derived(); // Error

    // エラー。実際のインスタンスが派生クラスであっても、基底クラスから派生
    // クラスへの参照は作れない
    // Derived& r = base; // error
}

