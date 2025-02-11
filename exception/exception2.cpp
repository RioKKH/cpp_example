#include <iostream>
#include <array>

int main()
{
    std::array<int, 1> a = {0};

    try {
        a[1000];
    }
    catch (std::out_of_range &e)
    {
        // エラー内容を示す文字列
        std::cout << e.what() << std::endl;;
    }
}
