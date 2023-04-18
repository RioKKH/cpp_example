#include <iostream>

class Base
{
private:
    // 非公開な仮想関数
    virtual void method();

public:
    void call_method()
    {
        method();
    }
};

void Base::method()
{
    std::cout << "Base::method()" << std::endl;
}

class Derived : public Base
{
    // 基底クラスで非公開トナていてもオーバーライドだけは出来る
    void method() override;
};

void Derived::method()
{
    std::cout << "Derived::method()" << std::endl;
    // Base::method(); // error. Base::methodは非公開なので呼び出せない
}

int main()
{
    Derived derived;
    derived.call_method(); // 非公開メンバーのオーバーライドが呼び出される

    return 0;
}
