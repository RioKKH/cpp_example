#include <iostream>
using namespace std;

template <typename T>
T getGreater(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << getGreater<int>(100, 200) << endl;
    cout << getGreater<double>(1.0, 2.0) << endl;
    cout << getGreater<char>('A', 'B') << endl;
    return 0;
}
