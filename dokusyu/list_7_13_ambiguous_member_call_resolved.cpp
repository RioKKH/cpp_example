#include <iostream>

/*
   他重軽傷おｎわかりやすい問題として、どの基底クラスから派生したのかが
   曖昧になるというものがある。以下のコードは本問題を解決したもの
   ambiguous conversion
*/
class Base
{
private:
    int value;

public:
    Base(int value) : value{value}
    {
    }

    void show();
};

void Base::show()
{
    std::cout << "this: " << this
        << "this->value: " << value << std::endl;
}

class DerivedA : public Base
{
public:
    DerivedA(int value) : Base{value}
    {
    }
};

class DerivedB : public Base
{
public:
    DerivedB(int value) : Base{value}
    {
    }
};

// DerivedAもDerivedBもBaseから派生していることに注意
class MoreDerived : public DerivedA, public DerivedB
{
public:
    MoreDerived(int d_a, int d_b)
        : DerivedA{d_a}, DerivedB{d_b}
    {
    }
};

int main()
{
    MoreDerived more_derived{42, 72};

    // DerivedAが継承したBase::show()の呼び出し
    std::cout << "move_derived.DerivedA::show()" << std::endl;
    more_derived.DerivedA::show();

    // DerivedBが継承したBase::show()の呼び出し
    std::cout << "move_derived.DerivedB::show()" << std::endl;
    more_derived.DerivedB::show();

    // DerivedAの参照を経由してBaseへの参照を取得
    Base& base1 = static_cast<DerivedA&>(more_derived);

    // DerivedAの参照を経由したので、DerivedAが継承したBase::show()の呼び出し
    std::cout << "base1.show()" << std::endl;
    base1.show();


    // DerivedBの参照を経由してBaseへの参照を取得
    Base& base2 = static_cast<DerivedB&>(more_derived);

    // DerivedBの参照を経由したので、DerivedBが継承したBase::show()の呼び出し
    std::cout << "base2.show()" << std::endl;
    base2.show();
}

