#include <iostream>

class S
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
