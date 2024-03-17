#include <iostream>

template <typename T, typename U = int>
class MyClass {
public:
    T data1;
    U data2;
};

int main() {
    MyClass<double> obj1; // T = double, U = int (default)
    MyClass<char, bool> obj2; // T = char, U = bool
    return 0;
}



