#include <iostream>

class Base
{
public:
    virtual void show_message() const
    {
        std::cout << "Baseのメンバー関数" << std::endl;
    }
};

template <typename T>
class Derived : public Base
{
public:
    void show_message() const override
    {
        std::cout << "Derivedのメンバー関数" << std::endl;
    }
};

int main()
{
    Base base; // Base
    Derived<int> d; // Derived

    Base& b = d; // Derived
    Base bd = d; // Base

    base.show_message(); // Base
    d.show_message(); // Derived
    b.show_message(); // Derived
    bd.show_message(); // Base
}
