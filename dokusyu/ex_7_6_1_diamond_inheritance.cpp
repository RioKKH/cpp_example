#include <iostream>
#include <string>

class Base
{
public:
    explicit Base(std::string name)
    {
        std::cout << "Base: " << name << std::endl;
    }
};

class DerivedA : virtual public Base
{
public:
    DerivedA() : Base{"DerivedA"}
    {
    }
};

class DerivedB : virtual public Base
{
public:
    DerivedB() : Base{"DerivedB"}
    {
    }
};

class MostDerived : public DerivedA, public DerivedB
{
public:
    MostDerived() : Base{"MostDerived"}
    {
    }
};

int main()
{
    MostDerived most_derived;
}
