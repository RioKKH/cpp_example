#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base constructor" << std::endl;
    }
    virtual ~Base()
    {
        std::cout << "Base destructor" << std::endl;
    }
};


class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived constructor" << std::endl;
    }
    ~Derived()
    {
        std::cout << "Derived destructor" << std::endl;
    }
};

void deallocate(Base* base)
{
    delete base;
}

int main()
{
    auto ptr = new Derived{};

    deallocate(ptr);

    return 0;
}

