#include <iostream>

class A
{
private:

public:
	void foo() const
	{
	}
};

class B
{
private:
	A a;

public:
	operator const A&()
	{
		return a;
	}
};

int main()
{
	B b;

	// b.foo() // Error
	static_cast<const A&>(b).foo();

	return 0;
}
