#include <iostream>
using namespace std;

void func1() {
    for (int i = 0; i < 100; i++) cout << 'o';
}

void func2() {
    for (int i = 0; i < 100; i++) cout << '.';
}

int main() {
    func1();
    func2();
    cout << endl;
    return 0;
}

