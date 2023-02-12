#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <chrono>
#include <functional>
#include "number.h"

using namespace std;
using namespace std::chrono;

/*
 * スレッド間でオブジェクトの共有を避ける。
 * これによってノックの手間とデッドロックの危険はなくなる
 * オブジェクトを共有した方が速かった(thread5.cppの方が速い)
 */

mutex m; // 排他制御のためのオブジェクト
// vector<int> primes; // 素数を格納するためのvector

// thread宣言時に引数を受け取る関数
// thread4に比べて参照を受け取るようにした為か実行速度が速くなっている
void threadFunc(int N, int start, vector<int>& primes)
{
    for (int n = start; n <= N; n += 3)
    {
        if (isPrime(n))
        {
            unique_lock<mutex> lock(m);
            primes.push_back(n);
        }
    }
}


int main()
{
    auto t0 = high_resolution_clock::now();

    const int N = 400000;

    vector<int> primesA{2, 3};
    vector<int> primesB{};
    // primes.push_back(2); // 2と
    // primes.push_back(3); // 3は入れておく

    thread threadA(threadFunc, N, 4, ref(primesA));
    thread threadB(threadFunc, N, 5, ref(primesB));

    // スレッドの終了を待つ
    threadA.join();
    threadB.join();

    size_t size = primesA.size() + primesB.size();
    cout << "素数の数:" << size << endl;

    // 2つのvectorを結合する
    primesA.reserve(size);
    primesA.insert(primesA.end(), primesB.cbegin(), primesB.cend());

    sort(primesA.begin(), primesA.end());
    report(primesA.cbegin(), primesA.cend());

    auto t1 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t1 - t0).count() / 1000. << "秒\n";
}
         
