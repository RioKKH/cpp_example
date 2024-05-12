#include <iostream>
using namespace std;

// C++20 関数の引数の型推論
// テンプレートの引数にautoを使うことで、関数の引数の型を推論できる
template <auto N>
auto multiplier(auto x) {
    return N * x;
}

template <auto N, typename T>
auto multiplier17(T x) {
    return N * x;
}

cout << multiplier<10>(10) << endl; // 100
cout << multiplier17<20, int>(10) << endl; // 200





