#include <iostream>

struct S {};

// 関数のオーバーロード
// 引数が左辺値参照の場合
int func(int& r) {
    std::cout << "Called by lvalue reference" << std::endl;
    return r;
}

// 引数が右辺値参照の場合
int func(int&& r) {
    std::cout << "Called by rvalue reference" << std::endl;
    return r;
}

int main() {

    // 左辺値参照: 従来の参照の事. 型名+&で宣言する
    // 右辺値参照: C++11で追加された参照の事. 型名+&&で宣言する
    //             論理積の演算子と見間違えやすいので注意
    // 参照の種類によってことなるオーバーロードを定義することが出来る

    // 整数型変数の宣言
    int a = 100;

    // lはaの左辺値参照
    int& l = a;
    // rは200の右辺値参照
    int&& r = 200;

    std::cout << l << std::endl; // 実行結果: 100
    std::cout << r << std::endl; // 実行結果: 200

    std::cout << func(l) << std::endl;
    std::cout << func(200) << std::endl;

    return 0;
}
