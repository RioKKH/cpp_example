#include <unordered_map>
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
    // キーがstring、値がintの単価マップ
    // これは無駄な一時オブジェクトを作るので、emplaceを使う方法が望ましい
    // emplaceはコンストラクタの引数をそのまま渡すので、一時オブジェクトを作らない
    std::unordered_map<std::string, int> price;
    price.insert(std::make_pair("餃子", 100));
    // emplaceによるデータの追加
    price.emplace("ラーメン", 200);
    // []によるデータの追加
    price["チャーハン"] = 300;
    // 重複したキーを指定すると、データは更新となる
    price["餃子"] = 150;
    // キーに対応するデータの表示
    std::cout << price["餃子"] << "円\n\n";
    // キーが登録されていないデータを表示すると0円データとして追加される
    std::cout << price["マーボ豆腐"] << "円\n\n";
    show(price);

    // find探索
    std::string key = "マーボ豆腐";
    std::cout << key << "の探索\n";
    price[key] = 400;

    auto it = price.find(key);
    if (it != price.end()) {
        std::cout << it->second << "円です\n";
    }
    else {
        std::cout << "登録されていません\n";
    }
#else
#endif
}

