#include <iostream>

struct S
{
    int data {}; // データメンバー

    void f() {std::cout << "not const" << std::endl; };     // 1
    void f() const {std::cout << "const" << std::endl; };   // 2

    // データメンバーへのリファレンスを返す
    int &get()
    {
        // データメンバーへのリファレンスを返す場合、returnには&を
        // つける必要がない。int &としてメンバ関数の宣言に&をつければよい
        return data;
    }

    // const版
    // constリファレンスを返すので変更不可
    int const &get() const
    {
        return data;
    }
};

int main()
{
    S s;
    s.f();              // 1
    s.get();

    S const cs;
    cs.f();             // 2
    // const修飾されたオブジェクトからconst修飾されたメンバー関数を呼び出す --> OK
    cs.get(); 
}
