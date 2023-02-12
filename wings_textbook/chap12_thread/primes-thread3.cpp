#include <thread>
#include <mutex>
#include "number.h"
using namespace std;

mutex m; // 排他制御のためのオブジェクト

void threadFunc(int N, int start)
{
    for (int n = start; n <= N; n += 3)
    {
        if (isPrime(n))
        {
            // mutexを獲得してロックする
            unique_lock<mutex> lock(m);
            cout << n << ", ";
        }
    }
}

int main()
{
    const int N = 100;

    cout << "2, 3, ";

    // thread宣言時に引数を与える方法
    thread threadA(threadFunc, N, 4); // 4から調べる
    thread threadB(threadFunc, N, 5); // 5から調べる

    // スレッドの終了を待つ
    threadA.join();
    threadB.join();
    cout << endl;
}

