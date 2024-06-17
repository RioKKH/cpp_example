#include <iostream>

// 適当な関数
int f(int x)
{
    return x;
}


using f_ptr = int (*)(int);
// 関数へのポインターを引数にとり関数へのポインターを戻り値として返す関数g
f_ptr g(f_ptr p)
{
    p(0);
    return p;
}

// 関数へのポインター変数であるptr宣言をf_pointerというエイリアス
// 宣言を使わずに書く場合
void test1()
{
    // 変数ptrの宣言
    // int (int)へのポインター
    int (*ptr)(int) = &f;
}

void test2()
{
    g(&f);
}

void test3()
{
    auto ptr = &g;
    // autoを使わずｎ書くと
    int (*(*ptr)(int(*)(int)))(int) = &g;
    /*
     * int(*        // 戻り値型前半
     *    (*ptr)    // 変数名
     *    (         // 関数の引数
     *        int (*)(int)  // 引数としての関数へのポインター
     *    )         // 関数の引数
     *)(int)        // 戻り値の型後半
     * = &g;        // 初期化子
     */
    // かなり分かりづらい。戻り値の型を後ろに書く文法を使う場合
    // auto (*ptr)(int (*)(int)) -> int (*)(int) = &g;
    /**
     * auto         // プレイスホルダー
     * (*ptr)       // 変数名
     * (int (*)(int)// 引数
     * -> int(*)(int)// 戻り値の型
     * = &g;        // 初期化子
     */
    // エイリアス宣言を使うと
    using func_ptr = int (*)(int);
    auto (*ptr)(func_ptr) -> func_ptr = &g;
    // 大分わかりやすくなる。
}

