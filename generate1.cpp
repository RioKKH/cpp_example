#include <iostream>
#include <algorithm>
#include <vector>

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
    kkh::show(v1);

    auto gen_zero = [](){ return 0; };
    auto gen_one = [](){ return 1; };

    std::generate(std::begin(v1), std::end(v1), gen_zero);
    kkh::show(v1);
    // v1は{0, 0, 0, 0, 0}

    std::vector<int> v2 = {1, 2, 3, 4, 5};
    kkh::show(v2);

    std::generate_n(std::begin(v2), 5, gen_one);
    kkh::show(v2);
    // v2は{1, 1, 1, 1, 1}

}
