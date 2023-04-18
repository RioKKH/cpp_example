#include <iostream>

class A
{
	static int counter; // static メンバー変数の宣言

public:
	A();

	static int get_counter();
};

int A::counter = 0; // static メンバー変数の定義と初期化

A::A()
{
	++counter;
}

int A::get_counter()
{
	return counter;
}

int main()
{
    A a1; // counter = 1
    std::cout << a1.get_counter() << std::endl;
    A a2; // counter = 2
    std::cout << a2.get_counter() << std::endl;
}

