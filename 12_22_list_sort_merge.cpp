#include <cstdint>
#include <iostream>
#include <list>

template <typename T>
void print_list(const std::list<T>& l)
{
    for (auto iter = l.begin(); iter != l.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<std::int32_t> il = {2, 4, 6, 8, 2, 4, 6, 8};

    il.sort(); // 昇順ソート
    print_list(il);

    // il.sort(f);
    // f(x, y)がtrueならxがyより先頭寄りにソートされる
    // ラムダ関数を用いて実装
    // テンプレートを用いた高階関数
    auto greater = [](int x, int y){ return x > y; };
    il.sort(greater);
    print_list(il);

    std::list<std::int32_t> il2 = {1, 3, 5, 7};
    il2.sort(greater);
    print_list(il2);

    il.merge(il2, greater); // mergeする。その結果、il2は空になる
    std::cout << "il1:" << std::endl;
    print_list(il);
    std::cout << "il2:" << std::endl;
    print_list(il2);

    return 0;
}
