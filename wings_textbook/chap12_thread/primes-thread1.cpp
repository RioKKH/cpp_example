#include <thread>
#include "number.h"

using namespace std;

const int N = 100; // グローバル変数
// スレッドの生成時に引数を使う方法が分かり次第グローバル変数から変更可能

// 3の倍数+1となる数だけを調べる関数
void threadFuncA()
{
    for (int n = 4; n <= N; n += 3)
    {
        // 素数だったら表示する
        if (isPrime(n))
        {
            cout << n << ", ";
        }
    }
}

// 3の倍数+2となる数だけを調べる関数
void threadFuncB()
{
    for (int n = 5; n <= N; n += 3)
    {
        // 素数だったら表示する
        if (isPrime(n))
        {
            cout << n << ", ";
        }
    }
}

int main()
{
    // 2と3は例外的なので先に表示させてしまう
    cout << "2, 3, ";

    thread threadA(threadFuncA);
    thread threadB(threadFuncB);

    // スレッドの終了を待つ
    threadA.join();
    threadB.join();
    cout << endl;
}

