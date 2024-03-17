#include <iostream>
using namespace std;

// 汎用的な型Ｔを定義
// 実際の呼び出しに応じてコンパイラが関数本体を自動的に
// インスタンシエーションしてくれる
template <typename T>
T getGreater(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << getGreater<int>(100, 200) << endl;
    cout << getGreater<double>(1.0, 2.0) << endl;
    cout << getGreater<char>('A', 'B') << endl;
    return 0;
}
