#include <iostream>
using namespace std;

// C++11のautoキーワードによる型推論の例
// 基本データ型の型推論
auto i = 10; // int型(整数の既定)
auto d = 123.45; // double型(浮動小数点数の既定)

// 右辺の初期化しに指定するリテラルの表記で型をコントロールする
auto u =10u; // unsigned int型(Uでも可)
auto l = 20L; // long型(lでも可)
auto ll = 200LL; // long long型(llでも可)
auto f = 123.45F; // float型(fでも可)
auto ld = 123.45L; // long double型(ldでも可)
auto b = true; // bool型 (他に解釈しようがないので)
auto c = 'A'; // char型 (他に解釈しようがないので)

// 変数や式からの型推論
auto i_v = i;      // iはint型なのでi_vもint型
auto i_e = i + 10; // i+10はint型に評価されるのでi_eもint型


// C++14の文字列型の型推論
// 文字列リテラルからの型推論
auto sc = "Hello, C++11!";  // const char*型
auto ss = "Hello, C++14!"s; // std::string型 C++14から

// C++11のポインタ型と参照型の型推論
// ポインタや参照からの型推論
// 下の2つは同じ意味
auto  i_p  = &i; // int*型
auto* i_p2 = &i; // int*型

auto& i_r = i; // int&型 (参照ではautoの方に&を付けるだけ)

int main() {
    auto i = 100;
    cout << i << endl;
    cout << *i_p2 << endl;
    return 0;
}


