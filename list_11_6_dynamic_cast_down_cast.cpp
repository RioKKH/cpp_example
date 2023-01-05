#include <endian.h>
#include <iostream>

class Base
{
public:
    virtual ~Base() {}; // 仮想デストラクタを定義してポリモーフィックにする
    // dynamic_castがつかえるのは仮想関数を持ったクラスのみ
    // このようなクラスをポリモーフィッククラス（多様性を持ったクラス）という。
    // デストラクタを必ず仮想関数にするので、この制限はないのと同じ

    // virtual ではないメンバー関数
    const char* get_class_name() const { return "Base"; }
};


class Derived : public Base
{
public:
    const char* get_class_name() const { return "Derived"; }
};


class MoveDerived : public Derived
{
public:
    const char* get_class_name() const { return "MoveDerived"; }
};


int main()
{
    Derived d; // 実際のオブジェクトはDerived型

    Base *pb = &d; // Base型へのポインターにする

    // Base型へのポインターを使っているので、Base型のメンバー関数が呼ばれる
    std::cout << pb->get_class_name() << std::endl;

    Derived *pd = dynamic_cast<Derived *>(pb); // Base型からDerived型へキャスト

    if (pd)
    {
        // キャスト成功
        // ポインターはDerived型なので、Derived型のメンバー関数が呼ばれる
        std::cout << pd->get_class_name() << std::endl;
    }
    else
    {
        // キャスト失敗
        // ポインターでのキャストに失敗した場合、dynamic_castはnullptrを返す
        std::cout << "dynamic_cast失敗" << std::endl;
    }

    // 実際のインスタンス型はDerived型なのでキャストは失敗する
    MoveDerived *pmd = dynamic_cast<MoveDerived *>(pb);

    if (pmd)
    {
        std::cout << pmd->get_class_name() << std::endl;
    }
    else
    {
        std::cout << "dynamic_cast失敗" << std::endl;
    }

    return 0;
}
