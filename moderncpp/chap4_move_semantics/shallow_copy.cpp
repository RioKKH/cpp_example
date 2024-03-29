#include <iostream>
#include <vector>

int main() {
    auto* x = new int(100);
    auto* y = x;
    *y = 200;
    // 実行結果:200 200
    std::cout << *x << " " << *y << std::endl;

    // 1000要素のベクターvをシャローコピーして先頭要素のみ書き換える
    // 丸ごとコピーするのではなく、ポインタのみをコピーするのが
    // シャローコピーといえる。
    // 普段Ｃ言語のポインタを使うときには、シャローコピーを意識して
    // プログラムを書くことが多いはず。なのでＣ言語プログラマーには
    // 用語はともかく、概念としては馴染み深いはず。
    auto* v = new std::vector<int>(1000);
    auto* w = v;
    (*v)[0] = 123;
    (*w)[0] = 456;
    // 実行結果:456 456
    std::cout << (*v)[0] << " " << (*w)[0] << std::endl;

    return 0;
}
