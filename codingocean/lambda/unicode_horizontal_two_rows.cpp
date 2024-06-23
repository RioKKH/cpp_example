#include <iostream>
#include <functional>
#include <type_traits>

template <typename T, size_t N>
constexpr size_t countof(const T (& arr)[N])
{ 
    return std::extent<T[N]>::value;
}

int main()
{
    int n = 5;
    int c = n / 2 + 1;
    // auto func = [](int x, int y){ return (x + y) % 2 == 1; };
    // 関数ポインタを使う
    // std::function<bool(int, int)> func = [](int x, int y){ return (x + y) % 2 == 1; };
    std::function<bool(int, int)> funcArray[2][5] = {
        [ ](int x, int y) -> bool { return (x + y) % 2 == 1; },
        [n](int x, int y) { return x == y || x == n+1-y; },
        [n](int x, int y) { return x == 1 || x == n || y == 1 || y == n; },
        [c](int x, int y) { return x == c || y == c;},
        [c](int x, int y) { return abs(x - c) + abs(y - c) < c; },
        [=](int x, int y) { return x==1 || x==n || y==c; },
        [=](int x, int y) { return x == 1 || y == 1 || y == c || y == n; },
        [n](int x, int y) { return x == 1 || y == n; },
        [n](int x, int y) { return x == 1 || y == n; },
        [n](int x, int y) { return x == 1 || x == n || y == 1 || y == n; },
    };

    for (int z=0; z < countof(funcArray); z++) {
        for (int y = 1; y <= n; y++) {
            for (auto& func : funcArray[z]) {
                for (int x = 1; x <= n; x++) {
                    std::cout << (func(x, y) ? "X" : " ");
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
