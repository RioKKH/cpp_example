#include <iostream>
#include <vector>

int main()
{
    std::vector<int> LIST = {32, 64, 128, 256, 512, 1024};

    for (const auto& a : LIST)
    {
        std::cout << a << std::endl;
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << (2 << i) << std::endl;
    }

    return 0;
}

