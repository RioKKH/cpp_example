#include <iostream>

class Base
{
public:
    virtual void show_class_name() const
    {
        std::cout << "Base" << std::endl;
    }
};

class Derived : public Base
{
public:
    // 仮想関数のオーバーライドは基底クラスの動作を変更するので、
    // 基底クラスへのポインターを使ったよびだしでも派生クラスで
    // オーバーライドしたメンバー関数が呼び出される。
    void show_class_name() const override
    {
        std::cout << "Derived" << std::endl;
    }
};

void show_class(Base& base)
{
    base.show_class_name();
}

int main()
{
    Derived derived;
    show_class(derived);

    return 0;
}

