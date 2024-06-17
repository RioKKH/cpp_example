#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

auto equal = [](auto first1, auto last1, auto first2, auto last2, auto pred)
{
    auto size1 = std::distance(first1, last1);
    auto size2 = std::distance(first2, last2);

    if (size1 != size2)
    {
        // 要素数が等しくなかった
        return false;
    }

    // 要素数が等しいことを確認
    // 下のfor文は要素数が等しい場合にしか実行されない
    for (auto i = first1, j = first2; i != last1; ++i, ++j)
    {
        if (!pred(*i, *j))
        {
            // pred(*i, *j)が1つでもfalseになる場合
            return false;
        }
    }
    // pred(*i, *j)が全てtrueになった場合
    return true;
};


int main()
{
    std::vector<double> v = {1.3, 2.2, 3.0, 4.9, 5.7};
    // std::vector<double> w = {1.3, 2.2, 3.0, 4.9, 5.7};
    std::vector<double> w = {1.9, 2.4, 3.8, 4.5, 5.0};

    // 小数点以下は誤差として切り捨てる比較
    auto comp = [](auto a, auto b)
    {
        return std::floor(a) == std::floor(b);
    };

    bool b = equal(std::begin(v), std::end(v), std::begin(w), std::end(w), comp);
    // bool b = std::equal(std::begin(v), std::end(v), std::begin(w), std::end(w), comp);
    std::cout << b << std::endl;
}
