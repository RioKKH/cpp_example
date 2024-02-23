#include <unordered_map>
#include <list>
#include <string>
#include <iostream>
#include <ostream>

// pair型表示用、挿入演算子のオーバーロード
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p)
{
    return s << p.first << " : " << p.second;
}


// どのコンテナもこれで全部表示できる
template<class C>
void show(const C& data) {
    for (const auto& d : data) {
        std::cout << d << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
#if 1
    // [商品コード]と[商品名、単価]のメニューマップ
    std::unordered_map<std::string, std::pair<std::string, int>> menu;
    // データ構築
    menu["a"] = {"餃子", 100};
    menu["b"] = {"ラーメン", 200};
    menu["c"] = {"チャーハン", 300};
    // emplaceでのデータ構築。上の書き方の方が見やすい
    menu.emplace("d", std::make_pair("エビマヨ", 400));
    // 全データ表示
    show(menu);

    // 売上データ C++17の構造化束縛を使ってみる
    struct SALE {std::string code; int num;};
    std::list<SALE>sales{ {"a", 10}, {"b", 20}, {"c", 30}, {"d", 40} };
    for (const auto& sale : sales) {
        auto  [name, price] = menu[sale.code];
        std::cout << name << " : " << price * sale.num << std::endl;
    }
#else
#endif
    return 0;
}

