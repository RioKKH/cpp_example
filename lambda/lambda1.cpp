#include <iostream>

void f(std::string x)
{
    std::cout << x;
}

int main()
{
    f("hello");
    [](auto x){ std::cout << x; }("\ngood-bye");
    /**
     * 上記式を分解すると以下のように書くことが出来る
     * ラムダ式         [](auto x){ std::cout << x; }
     * 関数呼び出し     ("\ngood-bye");
     * 今まではラムダ式を変数に代入していたが、変数に代入せず、定義してすぐに関数呼び出ししている
     */
}
