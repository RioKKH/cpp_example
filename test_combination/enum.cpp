#include <iostream>

enum class TYPE_e
{
    AAA = 0,
    BBB = 1,
    CCC = 2
};

class A
{
private:
    TYPE_e m_type;

public:
    A();
    ~A();

    void setType(TYPE_e type);
    void showType() const;
};

A::A()
{
}

A::~A()
{
}

void A::setType(TYPE_e type)
{
    m_type = type;
}

void A::showType() const
{
    std::cout << int(m_type) << std::endl;
}

int main()
{
    A a;
    a.setType(TYPE_e::AAA);
    a.showType();
    a.setType(TYPE_e::BBB);
    a.showType();
    a.setType(TYPE_e::CCC);
    a.showType();

    return 0;
}

