#include <iostream>
#include <vector>
#include <algorithm>

namespace kkh
{
    template<typename T> int show(const std::vector<T> &X)
    {
        for (const T &x : X)
        {
            std::cout << x;
        }
        std::cout << std::endl;
        return 0;
    }
}

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::fill(std::begin(v1), std::end(v1), 0);
    kkh::show(v1);
    // vは{0, 0, 0, 0, 0}

    std::vector<int> v2 = {1, 2, 3, 4, 5};
    std::fill_n(std::begin(v2), 5, 0);
    kkh::show(v2);
    // vは{0, 0, 0, 0, 0}
}


