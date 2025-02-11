// デリゲートコンストラクタ
// delegate constructor

#include <iostream>

struct S
{
    S() : S(1)
    {
        std::cout << "delegating constructor" << std::endl;
    }

    S(int n)
    {
        std::cout << "constructor" << std::endl;
    }
};

int main()
{
    S s;
    // constructor
    // delegating constructor
    // の順番で出力される
}
