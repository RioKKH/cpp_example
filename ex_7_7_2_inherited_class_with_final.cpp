#include <iostream>

class Base
{
public:
    Base()
    {
    }

    virtual void show()
    {
        std::cout << "base_show()" << std::endl;
    }
};

class Derived : public Base
{
public:
    void show() final
    {
        std::cout << "derived_show()" << std::endl;
    }
};

int main()
{
    Base base;
    Derived derived;

    base.show();
    derived.show();
};
