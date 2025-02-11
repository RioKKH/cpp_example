#include <iostream>
#include <array>

int main()
{
    auto print = [](auto s){ std::cout << s << std::endl; };

    std::array<int, 5> a;

    // aのバイト数
    print(sizeof(a));
    // 要素数:5
    print(a.size());
}

