#include <iostream>

/*
   他重軽傷おｎわかりやすい問題として、どの基底クラスから派生したのかが
   曖昧になるというものがある。以下のコードは本問題によりエラーとなるもの
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

    // DerivedAとDerivedB, どちらのBase::show()が使われる？
    more_derived.show();

    // DerivedAとDerivedB、どちらのBaseへの参照が代入される？
    Base& base = more_derived;

    base.show();
}
