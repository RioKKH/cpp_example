#include <iostream>

struct C
{
    int f(int)
    {
        return 0;
    }
};


int main()
{
    // メンバー関数へのポインター
    // 1. 関数fの型は int (int)
    // 2. そのポインター型は int (*)(int)
    // 3. 従って、クラス名Cのメンバー関数fへのポインター型は
    //    int (C::*)(int)になる
    int (C::*ptr)(int) = &C::f;

    // クラスのオブジェクト
    C object;

    // オブジェクトを指定したメンバー関数へのポインターをかいした関数呼び出し
    (object.*ptr)(123);
}
