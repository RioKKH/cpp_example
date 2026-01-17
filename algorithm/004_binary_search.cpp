#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 問題
 *
 *  整数 N 個の配列 A と、整数 M 個の配列 B が与えられます
 *  B の各要素 Bjついて、A の中にある要素のうち Bj以下で
 *  最大の値 を出力してください。
 *  もし Bj 以下の値が A に一つも存在しない場合は、
 *  -1 と出力してください。
 *
 *  制約:
 *      N,M≤2×105
 *      Ai, Bj ≤ 10^9
 *
 *      A はソートされていない状態で与えられる。
 *  ヒント： M 個の各要素に対して A を全部見ていると
 *  O(N×M) で間に合いません。
 *  A をあらかじめ std::sort しておき、std::upper_bound
 *  という関数を使うと高速に探せます。
 *
 *  ここで覚えておくべき事は、二分探索を使う必要が生じたら、
 *  C++の場合は upper_bound を使うということ。
 *  具体的なアルゴリズムは本読めば載っている。
 *
 *  A = {1, 3, 5, 8} でBj = 6の場合, upper_boundは8を指す。
 */

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<long long> A(N, 0);

    for (int i = 1; i <= N; i++)
    {
        std::cin >> A[i];
    }

    // 二分探索を使うために、予めAを昇順にソートする
    std::sort(A.begin(), A.end());

    // Bの各要素についてAの中から探す
    for (int i = 1; i <= M; i++)
    {
        int b;
        std::cin >> b;

        // upper_boundは"bより大きい最初の要素"を指すイテレータを返す
        auto it = std::upper_bound(A.begin(), A.end(), b);

        if (it == A.begin())
        {
            // もし最初の要素が既にbより大きければ、b以下の値は存在しない
            std::cout << -1 << std::endl;
        }
        else
        {
            // itの1つ前の要素が"b以下の最大値"になる
            it--;
            std::cout << *it << std::endl;
        }
        return 0;
    }

    return 0;
}
