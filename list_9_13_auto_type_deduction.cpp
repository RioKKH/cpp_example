#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30};

    // ネストした型はとても長ったらしくて、しかもミスしてしまうかもしれない
    // std::vector<T>::reference はT&を表すネストした型名である
    // エラー型を間違えてしまった (昔はvはstd::vector<float>だったのかもしれない
    std::vector<float>::reference r = v[0];

    // 添字をつかてアクセスしているため
    // 型を書かなくてもようそへの参照を取得しているだろうと考えられる
    // 添字演算子を使っているから要素への参照を取得しているはずだ、とわかるので
    // autoを使っても方の予想がついて、読むときに齟齬があまりない
    const auto& cr = v[0];
}
