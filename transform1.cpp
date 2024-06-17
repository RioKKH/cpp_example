#include <iostream>
#include <vector>
#include <algorithm>

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

auto transform = [](auto first, auto last, auto result, auto op)
{
    for (auto iter = first; iter != last; ++iter, ++result)
    {
        *result = op(*iter);
    }
    return result;
};

int main()
{
    std::vector<int> a = {1, 2, 3, 4, 5};

    std::vector<int> b(5, 0);
    // std::transform(std::begin(a), std::end(a), std::begin(b), [](auto x){ return 2*x; });
    transform(std::begin(a), std::end(a), std::begin(b), [](auto x){ return 2*x; });
    kkh::show(b);
    // bは{2, 4, 6, 8, 10}

    std::vector<int> c(5, 0);
    // std::transform(std::begin(a), std::end(a), std::begin(c), [](auto x){ return x%3; });
    transform(std::begin(a), std::end(a), std::begin(c), [](auto x){ return x%3; });
    kkh::show(c);
    // cは{1, 2, 0, 1, 2}

    std::vector<int> d(5, 0);
    // std::transform(std::begin(a), std::end(a), std::begin(d), [](auto x){ return x<3; });
    transform(std::begin(a), std::end(a), std::begin(d), [](auto x){ return x<3; });
    kkh::show(d);
    // dは{true, true, false, false, false}
}
