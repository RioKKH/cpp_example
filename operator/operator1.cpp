#include <iostream>

struct S {};

int operator +(S, S){ return 0; }
void operator -(S, S){ }

int main()
{
    S s;
    int x = s + s;
    std::cout << x << std::endl;
    s - s; // 戻り値は無い
}
