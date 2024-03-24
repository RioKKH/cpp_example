#include <iostream>
#include <vector>

int main() {
    // シャローコピーとは、ポインタのコピーのことである。
    // このシャローコピーがムーブセマンティクスの考え方
    // の基本となる。

    auto* x = new int(100);
    // yにシャローコピーしてxは用済みとしてマークする
    auto* y = x;
    x = nullptr;
    *y = 200;
    // *xは使えないので*yのみ表示する。実行結果: 200
    std::cout << *y << std::endl;

    auto* v = new std::vector<int>(1000);
    // wにシャローコピーしてvは用済みとしてマークする
    auto* w = v;
    v = nullptr;
    (*w)[0] = 456;
    // *vは使えないので*wのみ表示する。実行結果: 456
    std::cout << (*w)[0] << std::endl;

    return 0;
}
