#include <iostream>
#include <utility>

template <typename... T>
void eat(const T&...)
{
}

// 完全転送とはstd::forward()関数を使って右辺値と左辺値を区別した関数呼び出しの事
// 可変引数テンプレートの関数パラメータパックで参照やフォワーディング参照を受け取るには
// T&... や T&&... と記述します。
// また、それら関数パラメータパックを完全転送するにはstd::forward()関数を使いますが、
// パラメータパック拡張を使い、要素毎にstd::forward()関数で完全転送されるようにします
template <typename... T>
void fwd(T&&... values)
{
    // 完全転送
    eat(std::forward<T>(values)...);
}

int main()
{
    fwd(0, 1, 2, 3);
}
