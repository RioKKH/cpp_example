#include <iostream>

class BaseA
{
private:
    int value;

public:
    BaseA(int value) : value{value}
    {
    }

    void BaseA_show();
};

void BaseA::BaseA_show()
{
    std::cout << "this: " << this
        << "this->value: " << value << std::endl;
}

class BaseB
{
private:
    int value;

public:
    BaseB(int value) : value{value}
    {
    }

    void BaseB_show();
};

void BaseB::BaseB_show()
{
    std::cout << "this: " << this
        << "this->value: " << value << std::endl;
}

class Derived : public BaseA, public BaseB
{
public:
    Derived(int value_a, int value_b)
        : BaseA{value_a}, BaseB{value_b}
    {
    }
};

int main()
{
    Derived derived{42, 72};

    derived.BaseA_show();
    derived.BaseB_show();

    return 0;
}


