#include <iostream>
#include <vector>
#include <string>

/*
 * std::vectorは
 *   ランダムアクセスができるコンテナ
 *   イテレータはランダムアクセスイテレータ
 */
int main()
{
    // 空のコンテナ作成
    std::vector<int> iv; // 要素数0のint型std::vector

    // 要素数nのコンテナ作成
    std::vector<std::string> sv{5, "apple"};
    for (const auto& s : sv)
    {
        std::cout << s << std::endl;
    }

    // コンテナのイテレータ
    // イテレータによるインスタンス生成
    std::string s = "apple";

    // sの先頭から末尾をもとにstd::vectorを生成する
    std::vector<char> cv{s.begin(), s.end()};

    for (char c : cv)
    {
        std::cout << c << std::endl;
    }

    // ポインターもイテレータと機能するので、以下のようにインスタンスを
    // 生成することも可能
    const char fruit[] = "apple";
    std::vector<char> cv2{fruit, fruit + 5}; // fruitの先頭と6文字目(末尾)
    for (const auto& c : cv2)
    {
        std::cout << c << std::endl;
    }

    return 0;
}
