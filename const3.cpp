#include <iostream>

int main()
{
    // constのついている型のオブジェクト
    const int x = 0;

    // エラー、constがない
    // constのついているkたのオブジェクトをlvalueリファレンスで
    // 参照したい場合には、constがついている必要がある。
    // int &ref = x;

    // OK, constがついている
    const int &cref = x;
}
