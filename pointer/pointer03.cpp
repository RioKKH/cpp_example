#include <iostream>

//- 関数へのポインター

int f(int x)
{
    std::cout << x << std::endl;
    return x;
}

int main()
{
    // 関数の型。関数から関数名を取り除いたものが関数の型になる
    using f_type = int (int);

    // 関数へのポインター
    using f_pointer = f_type *;

    f_pointer ptr = &f;

    // 関数へのポインターを経由した関数呼び出し
    (*ptr)(123);

    // C++では特別に関数へのポインターはそのまま関数呼び出し
    // することが出来るようになっている。
    ptr(123); // == (*ptr)(123)                     
}
