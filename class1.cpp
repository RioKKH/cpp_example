#include <iostream>
#include <vector>

struct point
{
    int x = 0;
    int y = 0;
};

int main()
{
    std::vector<point> ps;

    // 変数の初期化は=, {}, ()のどれでも良い。
    /*
     * auto a = 1;
     * auto b(2);
     * auto c{3};
     * でどれでも有効
     */
    int x{};
    int y{};

    while(std::cin >> x >> y)
    {
        ps.push_back(point{x, y});
    }

    return 0;
}
