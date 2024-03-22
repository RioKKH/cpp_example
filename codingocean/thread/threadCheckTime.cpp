#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

steady_clock::time_point Start;
void startTimer() {
    Start = high_resolution_clock::now();
}

void func1(int num) {
    for (int i = 0; i < num; i++) cout << 'o';
}

void func2() {
    for (int i = 0; i < 500; i++) cout << '.';
}

int main() {

    // スレッドに引数を渡す場合
    thread th1(func1, 300); // create a thread to execute func1
    thread th2(func2); // create a thread to execute func2

    th1.join(); // wait for th1 to finish
    th2.join(); // wait for th2 to finish

    return 0;
}

