#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v0 = {0, 2, 4, 6, 8};
    std::vector<int> v1 = {1, 3, 5, 7, 9};

    v1 = v0;        // 同じ型のコンテナから代入演算子を用いて代入する
    v0 = {2, 3, 5}; // std::initializer_list<int>からの代入

    std::cout << "v0:" << std::endl;
    for (const auto& i : v0)
    {
        std::cout << " " << i << std::endl;
    }

    std::cout << "v1:" << std::endl;
    for (const auto& i : v1)
    {
        std::cout << " " << i << std::endl;
    }

    return 0;
}
