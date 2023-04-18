#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base constructor" << std::endl;
    }

    void method_Base()
    {
        std::cout << "Base::method_Base()" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived constructor" << std::endl;
    }

    void nmethod_Derived()
    {
        std::cout << "Derived::method_Derived()" << std::endl;
    }
};

int main()
{
    Derived derived;

    // Base& base = derived;
    // 派生クラスのポインターは基底クラスのポインターに暗黙変換可能。
    // ただし、基底クレスのポインターで出来ることは基底クラスで出来る事のみであり、
    // 派生クラスのメンバー関数などを呼び出すことは出来ない。
    Base* base = &derived;

    base->method_Base();
    // base->method_Derived();

    return 0;
}
