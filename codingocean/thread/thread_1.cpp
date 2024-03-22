#include <iostream>
#include <thread>
using namespace std;

void func1() {
    for (int i = 0; i < 500; i++) cout << 'o';
}

void func2() {
    for (int i = 0; i < 500; i++) cout << '.';
}

int main() {

    thread th1(func1); // create a thread to execute func1
    thread th2(func2); // create a thread to execute func2

    th1.join(); // wait for th1 to finish
    th2.join(); // wait for th2 to finish

    return 0;
}

