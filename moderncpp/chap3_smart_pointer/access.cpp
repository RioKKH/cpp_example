#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto u_int_ptr = make_unique<int>(99);
    auto s_str_ptr = make_shared<string>("shared");

    // operator *()で参照できる
    // 普通のポインタと同じように、関節参照演算子(*)や
    // アロー演算子(->)を使って、ポインタが指し示す
    // オブジェクトにアクセスできる
    cout << *u_int_ptr << endl; // 99
    cout << *s_str_ptr << endl; // shared

    // operator -> ()でsize関数を呼び出せる
    auto str_size = s_str_ptr->size();
    cout << str_size << endl; // 6

    return 0;
}



