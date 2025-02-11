#include <iostream>

class Base
{
public:
    virtual void method1()
    {
        std::cout << "Base::method1()" << std::endl;
    }

    virtual void method2()
    {
        std::cout << "Base::method2()" << std::endl;
    }
};

class Derived : public Base
{
public:
    // このメンバーはこれ以上オーバーライド出来ない
    void method1() final
    {
        std::cout << "Derived::method1()" << std::endl;
    }

    // こちらは単なるオーバーライド
    void method2() override
    {
        std::cout << "Derived::method2()" << std::endl;
    }
};

class MoreDerived : public Derived
{
public:
    // エラー。Derivedでfinal指定されているので
    // オーバーライドすることができない
    // void method1() override;

    // OK. オーバーライドを更にオーバーライドすることは出来る
    void method2() override
    {
        std::cout << "MoreDerived::method2()" << std::endl;
    }
};

int main()
{
    Derived derived;
    MoreDerived more_derived;

    derived.method1();
    derived.method2();

    more_derived.Base::method1();
    more_derived.method2();

    return 0;

}

