#include <iostream>

class A
{
private:

public:
	void foo()
	{
		std::cout << "A::foo" << std::endl;
	}
};

class B
{
private:
	A a;

public:
	// メンバー変数のaを返す変換関数
	operator A&()
	{
		return a;
	}
};


int main()
{
	B b;
	b.foo(); // Error. Bはfooというメンバー関数を持たない
}
