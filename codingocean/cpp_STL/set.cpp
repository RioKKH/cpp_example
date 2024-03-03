#include <iostream>
#include <set>

int main(int argc, char *argv[])
{
    // 整数を記憶する平衡2分木
    std::set<int> tree;
    // データ構築
    tree.emplace(5);
    tree.emplace(3);
    tree.emplace(2);
    tree.emplace(1);
    tree.emplace(4);
    // 全表示
    // 平衡2分木は昇順に並ぶため、1, 2, 3, 4, 5の順に表示される
    for (const auto& num : tree)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 探索
    int num = 2;
    std::cout << num << "は";
    auto it = tree.find(num);
    if (it != tree.end())
    {
        std::cout << "あった";
    }
    else
    {
        std::cout << "なかった";
    }
    std::cout << std::endl;

    return 0;
}
