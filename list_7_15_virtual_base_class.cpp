#include <iostream>

class Base
{
public:
    void method_Base()
    {
        std::cout << "Base: " << this << std::endl;
    }
};

// diamond inheritance
// DerivedAは仮想基底クラスとしてBaseを継承する
class DerivedA : virtual public Base
{
public:
    void method_DerivedA()
    {
        std::cout << "DerivedA: " << this << std::endl;
    }
};

// DerivedBは仮想基底クラスとしてBaseを継承する
class DerivedB : virtual public Base
{
public:
    void method_DerivedB()
    {
        std::cout << "DerivedB: " << this << std::endl;
    }
};

// DerivedAもDerivedBもBaseから派生しているが、
// Baseは仮想基底クラス指定されているので
// MoreDerivedにはBaseはただ1つしか存在しない
class MoreDerived : public DerivedA, public DerivedB
{
public:
    void method_MoreDerived()
    {
        std::cout << "MoreDerived: " << this << std::endl;
    }
};

int main()
{
    MoreDerived more_derived;
    // Baseが本当に1つしか存在しないのか、つまりDerivedAからみたBase
    // とDerivedBから見たBaseが同じものかどうかはthisポインターを見れば
    // 分かります。

    std::cout << "DerivedA" << std::endl;
    DerivedA& derived_a = more_derived;
    derived_a.method_Base();

    std::cout << std::endl;

    std::cout << "DerivedB" << std::endl;
    DerivedB& derived_b = more_derived;
    derived_b.method_Base();
}

