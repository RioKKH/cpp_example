#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto u_int_ptr = make_unique<int>(100);
    auto s_str_ptr = make_shared<string>("hello");

    // スマートポインタのインスタンスをbool型のコンテキストで評価すると、
    // bool型としての評価で所有権の有無を確認できる。
    bool is_own_i = (bool)u_int_ptr;
    cout << "is onw int:" << is_own_i << endl;

    // if文の条件式にも使える
    if (s_str_ptr) {
        cout << "s_int_ptr has memory." << endl;
    } else {
        cout << "s_int_ptr does not have memory." << endl;
    } 

    return 0;
}




