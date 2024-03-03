#include <iostream>
#include <map>

// pair型表示用、挿入演算子のオーバーロード
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p)
{
    return s << p.first << ":" << p.second;
}

// どのコンテナもこれで全表示できる
template <class C>
void show(const C& data)
{
    for (const auto& d : data)
    {
        std::cout << d << std::endl;
    }
    std::cout << std::endl;
}

int main(int arc, char* argv[])
{
    // 平衡二分木データのいれもの
    std::map<std::string, int> price;
    // データこ構築
    price["ぎょうざ"] = 100;
    price["らーめん"] = 200;
    price["ちゃーはん"] = 300;
    price["えびまよ"] = 400;
    // mapはキーでソートされる
    show(price);
    // 探索
    std::string key = "すーさん";
    std::cout << key << ' ';
    auto it = price.find(key);
    if (it != price.end())
    {
        std::cout << it->second << "えん";
    }
    else
    {
        std::cout << "ない";
    }

    return 0;
}
