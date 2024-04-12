#include <iostream>
#include <vector>

int main() {
    std::vector<int> v(1000);
    
    // vを右辺値化する
    // std::moveは左辺値を右辺値に変換する
    // vectorクラスのムーブコンストラクタが呼ばれる
    // ムーブコンストラクタの呼び出しで結果としてvは使えなくなる
    // (nullptrが入る)のでそのあとは代入や参照などの一切の操作ができない
    // move()関数自体は右辺値参照を返すだけで、ムーブ自体を行わない!!
    auto w = std::vector<int>(std::move(v));

    // v[0] = 123; // vは無効なので実行時にエラーとなる
    w[0] = 456;
    std::cout << w[0] << std::endl;

    return 0;
}



