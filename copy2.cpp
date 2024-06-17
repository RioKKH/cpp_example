#include <iostream>
#include <vector>
#include <algorithm>

namespace kkh {
    int show(const std::vector<int> &X)
    {
        for (const auto &x: X)
        {
            std::cout << x;
        }
        std::cout << std::endl;
        return 0;
    }
}

int main()
{
    std::vector<int> source = {1, 2, 3, 4, 5};

    // 要素数5のvector
    std::vector<int> destination(5, 0);
    kkh::show(destination);

    auto result = std::copy(std::begin(source), std::end(source), std::begin(destination));

    // destinationの中身は{1, 2, 3, 4, 5}
    kkh::show(source);
    kkh::show(destination);
}
