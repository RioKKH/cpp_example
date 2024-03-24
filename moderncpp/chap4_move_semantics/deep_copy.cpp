#include <iostream>
#include <vector>

int main() {
    // 整数型変数xをyにコピーしてそれぞれ書き換える
    int x = 100;
    auto y = x;
    y = 200;
    std::cout << x << " " << y << std::endl; // 実行結果: 100 200
                                             // これは普通の感覚で理解できる

    // 1000要素のベクターvをwにコピーして 先頭要素のみ書き換える
    std::vector<int> v(1000);
    // これもコピーになる。コピー構築と呼ばれる
    // 参照ではないので、vの要素を書き換えてもwには影響しない
    auto w = v;
    v[0] = 123;
    w[0] = 456;
    std::cout << v[0] << " " << w[0] << std::endl; // 実行結果: 123 456

    return 0;
}
