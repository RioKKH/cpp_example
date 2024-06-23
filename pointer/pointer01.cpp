#include <iostream>

void test1()
{
    // int *型へのリファレンス
    using type = int * &;
    // リファレンス型へのポインター型は出来ない。
    // 意味が無いから
    // using error = int & *; // error
}

void test2()
{
    // リファレンスはポインターのシンタックスシュガーで、
    // 簡便のために機能を制限したもの。
    // リファレンスは参照先のオブジェクトと全く同じように振る舞う
    // 従って、リファレンス自体のポインターの値を得ることは出来ない
    // ポインター型変数へのポインターを得ることは出来ないことと
    // 対比して覚えておきたい。

    // リファレンスからポインターの値を得るには&を用いれれば良い
    int data {}; // dataを0で初期化
    int &ref = data; 
    // 以降refはdataのリファレンスになる
    // 従って、以下の&refは&dataと同じことになる。
    int *ptr = &ref;
}

void test3()
{
    int *ptr = nullptr;
    // ptrを参照する
    int * &ref = ptr; // (int *) &refと書くとわかりやすいか
    // 以降refはptrと全く同じものになる。

    int data {};
    // ptrの値が&dataになる
    ref = &data;
    // refはptrと全く同じもの(別名をつけただけのもの)なので、
    // refの変更はptrの変更になるということ

    // test
    if (ref == ptr)
    {
        std::cout << "Same!" << std::endl;
    } else {
        std::cout << "Different!" << std::endl;
    }
}

void test4()
{
    // constとpointerの組み合わせ

    // 型T
    using T = int;

    // どちらもconstなT
    // const TとT constが同じ型であることを思い出せば、
    // const_T_1とconst_T_2は同じ型であることがわかる
    using const_T_1 = const T;
    using const_T_2 = T const;

    // 型Tへのポインター版
    using T_pointer = T *;

    // どちらもconstなTへのポインター
    // これもどちらも同じ型になる。
    using const_T_pointer_1 = const T *;
    using const_T_pointer_2 = T const *;

    // Tへのconstなポインター
    using T_const_pointer = T * const;
    
    // どちらもconstなTへのconstなポインター
    using const_T_const_pointer_1 = const T * const;
    using const_T_const_pointer_2 = T const * const;


    {
        using const_T_1 = const T;
        using const_T_2 = T const;
        using const_T_pointer_1 = const T *;
        using const_T_pointer_2 = T const *;

        const int x {};
        const int *ptr = &x;
        // これは(const int) *ptrの意味。つまりconstなのは
        // 参照先のオブジェクトであってポインターではない

        // error
        // constな参照先を変更出来ない
        // *ptr = 0;

        int y {};
        // OK
        // ポインターはconstではないので、値が変更出来る
        ptr = &y;
    }

    {
        // constではない
        int data = 123;

        // OK
        const int &ref = data;
        // OK
        const int *ptr = &data;
        // リファレンスやポインターはconst int扱いなので、
        // リファレンスやポインターを経由して読む事は出来るが、
        // 変更することは出来ない。以下その例となる。
        // error
        // 変更出来ない
        // *ptr = 0;
        // OK
        // 変更出来る
        data = 0;
    }

    {
        // Tへのconstなポインター
        using T_const_pointer = T * const;
        /**
         * これはポインターがconstなのであって、Tはconstではない
         * 従って、ポインターを経由して参照先を変更することは出来るが
         * ポインターの値自体は変更出来ない型となる
         * T * const == T (* const)ということかな
         */
        int data {};

        // constなポインター
        int * const ptr = &data;
        // OK、参照先は変更出来る
        *ptr = 1;
        //error、値は変更出来ない
        // ptr = nullptr;
    }

    {
        // どちらもconstなTへのconstなポインター
        using const_T_const_pointer_1 = const T * const;
        using const_T_const_pointer_2 = T const * const;
        /**
         * constなTなので、ポインターを経由して参照先を
         * 変更することは出来ないし、constなポインターなので、
         * ポインターの値を変更することも出来ない。
         */

        int data = 123;
        int const * const ptr = &data;

        // OK、参照先は読める
        int read = *ptr;
        // error、参照先は変更出来ない
        // *ptr = 0;
        // error、ポインターは変更出来ない
        // ptr = nullptr;
    }
}




int main()
{
    test1();
    test2();
    test3();
    test4();
}

