#include <iostream>

struct C
{
    int x = 1;
    int y = 2;
};

//- クラス名Cのメンバー名Mのメンバーへのポインター取得方法
void test1()
{
    int C::* x_ptr = &C::x;
    int C::* y_ptr = &C::y;

    C object;

    // 1
    std::cout << object.*x_ptr << std::endl;

    // 2
    std::cout << object.*y_ptr << std::endl;
}

//- 分かりづらい場合にはエイリアス宣言を用いる
void test2()
{
    using type = int C::*;
    type x_ptr = &C::x;
    type y_ptr = &C::y;

    //- もしくはautoを使う手もある
    // auto x_ptr = &C::x;
    // auto y_ptr = &C::y;

    C object;

    // 1
    std::cout << object.*x_ptr << std::endl;

    // 2
    std::cout << object.*y_ptr << std::endl;
}

int main()
{
    test1();
    test2();
}

