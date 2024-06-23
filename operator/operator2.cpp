#include <iostream>

struct S {};

// S f(S, S)のようなもの
S operator +(S, S){}

int main()
{
    S s;
    // f(s, s)のようなもの
    operator +(s, s);
}
