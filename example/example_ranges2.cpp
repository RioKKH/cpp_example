#include <iostream>
#include <vector>
#include <ranges>
#include <stdexcept>

int main()
{
    namespace rv = std::ranges::views;
    try {
        // ネストされたベクターを準備する
        std::vector<std::vector<int>> nestedVec = {{1, 2}, {3, 4, 5}, {6, 7}};

        auto result = nestedVec
            | rv::join // ネストされたベクトルを単一のベクトルになるように結合する
            | rv::reverse // ベクターを逆順にする
            | rv::take(3) // ベクターの最初のn要素を取得する
            | rv::transform([](int n) { return n * 2; }); // 要素を指定した関数で変換する

        // エラー処理: 要素が足りない場合
        // std::distance()を使って、resultベクトルの要素数を確認し、
        // 要素が足りない場合にはエラーをthrowする。
        if (std::ranges::distance(result.begin(), result.end()) < 3)
        {
            throw std::runtime_error("Not enough elements in the range.");
        }

        for (const auto val : result)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } 
    catch (const std::exception e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

