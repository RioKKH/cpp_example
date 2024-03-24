#include <iostream>
#include <thread>
using namespace std;

void print(char symbol) {
    for (int i = 0; i < 200; i++) {
        cout << symbol;
    }
}

int main() {
    thread th(print, 't');
    // th.join(); // もしここにjoin()を入れると、単に順番に実行されるだけ
    print('m');
    th.join();

    return 0;
}
