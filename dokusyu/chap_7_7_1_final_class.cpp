#include <iostream>

class Base
{
};

// final指定子を用いて、このクラスはこれ以上派生させないと明示する
// もうこれ以上派生出来なくする
class FinalClass final : public Base
{
};

// エラー。final指定されたクラスを継承することは出来ない
class MoreDerived : public FinalClass
{
};

int main()
{
    FinalClass final_class;
    MoreDerived more_derived;

    retrun 0;
}
