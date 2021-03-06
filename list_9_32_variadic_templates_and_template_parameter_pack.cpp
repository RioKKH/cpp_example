#include <iostream>

// ここの...は可変引数テンプレート variadic templates
template <typename... T>
void function(T&&... args);

// 引数の数が可変なテンプレート関数
template <typename... T>
void foo(T... args)
{
    function<T...>(args...); // ここの...はどちらも展開構文(expansion)
    // 例えばfoo<int, float, char>(1, 2.f, 3)と呼び出されたバイ、実体化のときに
    // void foo(int args_1, float args_2, char args_3)のようになるので
    // パラメータパックが展開されると
    // function<int, float, char>(args_1, args_2, args_3)
    // に置き換わる
}
