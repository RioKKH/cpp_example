#include <iostream>
#include <algorithm>

auto equal = [](auto first1, auto last1, auto first2, auto last2)
{
    // 要素数が等しいことを確認
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
        if (*i != *j)
        {
            // 等しくない要素が1つでもあった場合
            return false;
        }
    }
    // 各要素が全て等しかった
    return true;
};
