#include <vector>
#include <chrono>
#include <algorithm> // sort()
#include "number.h"

using namespace std;
using namespace std::chrono;

int main()
{
    auto t0 = high_resolution_clock::now();

    const int N = 400000;

    vector<int> primes;

#pragma omp parallel // このブロックの中が並列処理される
#pragma omp for schedule (dynamic, 1000) // このブロックの直後に書いたfor文が並列処理される
    // 素数かどうかを調べる数を1000個たんいでスレッドに渡している。これはハイパラで調整が必要
    // schedule(guided) とする方法があるらしが、この場合では遅くなるとのこと
// #pragma omp for parallel for schedule (dynamic, 1000) // 1行にまとめてもOK
    for (int n = 2; n <= N; ++n)
    {
        if (isPrime(n))
        {
#pragma omp critical // この記述の愚痴に書く分が排他制御の対象になる
            primes.push_back(n);
        }
    }

    cout << "素数の数:" << primes.size() << endl;

    // 素数を列挙し終わった直後のvectorの要素は順番がバラバラになっている為、並べ替える必要あり
    sort(primes.begin(), primes.end());
    // cbegin(), cend()は読み取り専用イテレータ
    report(primes.cbegin(), primes.cend());

    auto t1 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t1 - t0).count() / 1000. << "秒\n";
}
