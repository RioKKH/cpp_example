#include <iostream>
#include <unordered_map>

/**
 * ハッシュテーブルをunordered_mapで実装する
 */

int main()
{
    // キーがstring, 値がintの単価マップ
    std::unordered_map<std::string, int> price;

    // データの追加
    price["餃子"] = 100;
    price["ラーメン"] = 200;
    price["チャーハン"] = 300;

    // データの表示
    std::cout << price["餃子"] << std::endl;
    std::cout << price["ラーメン"] << std::endl;
    std::cout << price["チャーハン"] << std::endl;

    return 0;
}

