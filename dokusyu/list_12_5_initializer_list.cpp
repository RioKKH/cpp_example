#include <iostream>
#include <vector>

int main()
{
    // std::initializer_listによる生成
    // 見かけ上、配列の初期化と同じ記述になっている
    std::vector<int> iv = {1, 2, 3, 4, 5};

    for (int i : iv)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
