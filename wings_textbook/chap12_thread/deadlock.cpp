#include <thread>
#include <mutex>
#include "number.h"
using namespace std;

const int N = 100; // グローバル変数
// coutとtotalのそれぞれで排他制御を行うため、mutexオブジェクトを2つにしてみる
mutex m1, m2;  // 排他制御のためのオブジェクト
int total = 0; // 素数の数を数える

void threadFuncA()
{
    for (int n = 4; n <= N; n += 3)
    {
        // 素数だったら表示する
        if (isPrime(n))
        {
            unique_lock<mutex> lock1(m1); // mutexを獲得する
            cout << n << ", ";
            unique_lock<mutex> lock2(m2); // mutexを獲得する
            ++total;
        } // mutexを開放する
    }
}

void threadFuncB()
{
    for (int n = 5; n <= N; n += 3)
    {
        // 素数だったら表示する
        if (isPrime(n))
        {
            unique_lock<mutex> lock1(m2);
            cout << n << ", ";
            unique_lock<mutex> lock2(m1);
            ++total;
        }
    }
}

int main()
{
    cout << "2, 3, ";

    thread threadA(threadFuncA);
    thread threadB(threadFuncB);

    threadA.join();
    threadB.join();

    cout << endl;
}
