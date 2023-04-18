#include <iostream>
#include <vector>

int main()
{
    std::vector<int> iv = {1, 2, 3, 4, 5};
    iv.resize(4); // 切り詰める方向にリサイズする
    std::cout << "size() = "<< iv.size() << std::endl;

    iv.resize(6, -1); // 伸ばす方向にリサイズする。新しく増えた部分は-1で初期化される
    std::cout << "size() = "<< iv.size() << std::endl;

    for (const auto& i : iv)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

