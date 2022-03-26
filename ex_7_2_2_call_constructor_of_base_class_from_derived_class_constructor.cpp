#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base constructor" << std::endl;
    }

    explicit Base(int i)
    {
        std::cout << "Base constructor: " << i << std::endl;
    }

    ~Base()
    {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived consturctor" << std::endl;
    }

    explicit Derived(int i) : Base{i}
    {
        std::cout << "Derived constructor with argument: " << i << std::endl;
    }

    ~Derived()
    {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main()
{
    Derived derived{42};
}

