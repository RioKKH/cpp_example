#include <iostream>

struct X {int a;};
struct Y {int a;};

void operator +(X, Y) {}
void operator +(Y, X) {}

// 2つの順序の二項演算子のオーバーロードが必要になる
int main()
{

    X x{1};
    Y y{2};

    // +(X, Y)
    x + y;

    // +(Y, X)
    y + x;
}


