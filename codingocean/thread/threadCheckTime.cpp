#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

// system_clock はシステム全体の時刻を表す
// steady_clock はモノトニックな時刻を表す
// steady_clock::time_point start;
system_clock::time_point start;
void startTimer() {
    // start = steady_clock::now();
    start = high_resolution_clock::now();
}

void stopTimer() {
    // auto end = steady_clock::now();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "duration: " << duration.count() / 1000000.0 << endl;
}

typedef unsigned long long ull;
void sumOdd(ull end) {
    ull sum = 0;
    for (ull i = 1; i <= end; ++i) {
        if (i & 1) { //  1bit目が1の場合
            sum += i;
        }
    }
    cout << "sumOdd: " << sum << endl;
}

void sumEven(ull end) {
    ull sum = 0;
    for (ull i = 1; i <= end; ++i) {
        if (!(i & 1)) { // 1bit目が0の場合
            sum += i;
        }
    }
    cout << "sumEven: " << sum << endl;
}



void func1(int num) {
    for (int i = 0; i < num; i++) cout << 'o';
}

void func2() {
    for (int i = 0; i < 500; i++) cout << '.';
}

int main() {

    ull num = 1000000000;

    startTimer();
    sumOdd(num);
    sumEven(num);
    stopTimer();

    startTimer();
    thread th1(sumOdd, num);
    thread th2(sumEven, num);
    th1.join();
    th2.join();
    stopTimer();

    return 0;
}

