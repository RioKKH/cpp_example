#include <iostream>
using namespace std;

// C++11 関数の戻り値の型をautoで指定(後置型)
// autoは型推論の意味は持たず単なるプレースホルダー
// として使われる。
auto func() -> int {
    return 100;
}

// C++11でつかえるようになったdecltypeを用いて
// 戻り値の型を指定することもできる。
// 冗長でわざわざ感がある。
auto func() -> decltype(100) {
    return 100;
}

// C++14からの手法 関数の戻り値の型推論(auto)
// C++11の後置構文のようなプレースホルダーとしての
// 働きではなく、型推論の為の指定として働く。
auto func2() {
    return 100; // 戻り値の型は整数型と推論される
}

// 全てのreturn文で同じ型に推論出来る必要があるが、
// 以下の表記では推論される型が異なるためエラーとなる。
auto func3(int a) {
    if (a == 0) {
        return 1.0; // 浮動週数点数型の推論される
    } else {
        return 1;   // 整数型が推論される
    }
}

int main() {
    auto i = func2();
    cout << i << endl;
    return 0;
}





