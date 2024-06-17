#include <iostream>

/**
 * 関数を変数に代入出来るということは、関数を関数の引数として与えることが
 * 出来るということ。
 */
int main()
{
    // 関数を引数に取り呼び出す関数
    auto call_func = [] ( auto func )
    {
        func(123);
    };

    // 引数を出力する関数
    auto print = [] (auto x) { std::cout << x; };

    // 関数に関数を引数として与える
    call_func(print);

    // 引数を2倍して出力する関数
    auto print_twice = [] (auto x) { std::cout << 2*x; };

    // 関数に関数を引数として与える
    call_func(print_twice);
}

