#include <iostream>
#include <vector>
#include <algorithm>

/**
 * ムーブセマンティクスを理解するまでは完全な実装は出来ない
 * 以下は不完全な例。何が不完全なのか現時点ではわからない
 */
auto remove_if = [](auto first, auto last, auto pred)
{
    // removeする最初の要素
    auto removing = std::find_if(first, last, pred);

    // removeする要素がなかった
    // 要素がないので、イテレータremovingが最後の次を指すlastに等しくなっている
    if (removing == last)
    {
        return last;
    }

    // removeする要素の次の要素
    auto remaining = removing;
    ++removing;

    // removeする要素に上書きする
    for (; remaining != last; ++remaining)
    {
        // 上書き元も取り除くのであればスキップ
        if (pred(*remaining) == false)
        {
            *removing = *remaining;
            ++removing;
        }
    }
    // 新しい終端イテレータ
    return removing;
};
