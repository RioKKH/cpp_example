#include <iostream>

class A
{
public:
	operator int() const // int型に変換する変換関数 conversion function
	{
		return 0;
	}
};

class B
{
public:
	// explicit指定されたintへの変換関数
	explicit operator int() const
	{
		return 0;
	}
};


int main()
{
	A a;
	int ia = a; // OK. 変換関数はexplicit指定されていない
	char ca = a; // OK. intに暗黙変換されたあと、charに代入される

	B b;
	/*
	int ib = b; // Error. 変換関数がexplicit指定されているので,
				// Bからintへの暗黙型変換は行われない
				//
	char cb = b; // Error. intへの暗黙型変換が禁止されているので、charへも代入出来ない
	*/

	int j(b); // OK. 変数jは変換関数の戻り値で初期化される
	int k = static_cast<int>(b); // 明示的にキャストした場合は変換関数が呼ばれる

	return 0;
}

