#include <iostream>
#include <algorithm>
#include <vector>

namespace kkh
{
    template<typename T>
    int show(const std::vector<T> &X)
    {
        for (const T &x : X)
        {
            std::cout << x;
        }
        std::cout << std::endl;
        return 0;
    }
}

auto replace = [](auto first, auto last, auto old_value, auto new_value)
{
    for (auto iter = first; iter != last; ++iter)
    {
        if (*iter == old_value)
        {
            *iter = new_value;
        }
    }
};

int main()
{
    std::vector<int> a = {1, 2, 3, 3, 4, 5, 3, 4, 5};
    // std::replace(std::begin(a), std::end(a), 3, 0);
    replace(std::begin(a), std::end(a), 3, 0);
    // aは{1, 2, 0, 0, 4, 5, 0, 4, 5}
    kkh::show(a);

    return 0;
}
