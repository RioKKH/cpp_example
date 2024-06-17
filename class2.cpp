#include <iostream>

struct S
{
    int x;
    int y;
    int z;
};

int main()
{
    // 初期化
    // クラスのデータメンバーの定義順に初期化される
    S s {1, 2, 3};
    // s.x == 1;
    // s.y == 2;
    // s.z == 3;
    std::cout << s.x << std::endl;
    std::cout << s.y << std::endl;
    std::cout << s.z << std::endl;

    // S s {1, 2};
    // s.x == 1;
    // s.y == 2;
    // s.z == 0;
}
