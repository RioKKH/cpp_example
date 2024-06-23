#include <iostream>
#include <functional>

int main()
{
    int n = 5;
    int c = n / 2 + 1;
    // auto func = [](int x, int y){ return (x + y) % 2 == 1; };
    // 関数ポインタを使う
    // std::function<bool(int, int)> func = [](int x, int y){ return (x + y) % 2 == 1; };
    std::function<bool(int, int)> funcArray[] = {
        [](int x, int y){ return (x + y) % 2 == 1; },
        [n](int x, int y){ return x == y || x == n+1-y; },
        [n](int x, int y){ return x == 1 || x == n || y == 1 || y == n; },
        [c](int x, int y){ return x == c || y == c;},
        [c](int x, int y){ return abs(x - c) + abs(y - c) < c; },
    };

    for (int y = 1; y <= n; y++) {
        for (auto& func : funcArray) {
            for (int x = 1; x <= n; x++) {
                std::cout << (func(x, y) ? "X" : " ");
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    /*
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            // // 対角線上に X を表示
            // std::cout << (x == y ? "X" : " ");
            // // 交互に表示
            // std::cout << ((x + y) % 2 ==  1 ? "X" : " ");
            std::cout << (func(x, y) ? "X" : " ");

        }
        std::cout << std::endl;
    }
    */

    return 0;
}
