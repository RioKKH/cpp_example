#include <iostream>
#include <memory>
using namespace std;

int main() {
    // C++11/++14/++17/++20 配列の利用
    // スマートポインタを使って配列を扱う方法
    // 利用可能なバージョンが異なるので注意

    // 型名[] をテンプレート引数に指定してコンストラクタを呼ぶ
    unique_ptr<int[]> u_int_array_ptr(new int[10]);
    shared_ptr<int[]> s_str_array_ptr(new string[10]);  // C++17以降

    // make_unique<T>関数などを使う
    auto u_int_array_ptr2 = make_unique<int[]>(10); // C++14以降
    auto s_str_array_ptr2 = make_shared<string[]>(10); // C++20以降

    // operator [](size_t) を使って配列要素にアクセス
    for (int i = 0; i < 10; i++) {
        u_int_array_ptr[i] = i;
        s_str_array_ptr[i] = to_string(i); / / C++17以降
    }
    for (int i = 0; i < 10; i++) {
        cout << u_int_array_ptr[i] << " ";
        cout << s_str_array_ptr[i] << endl;
    }

    return 0;
}




