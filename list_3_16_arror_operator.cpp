#include <iostream>

class A
{
public:
	void foo();
};

void A::foo()
{
	std::cout << "A::foo()" << std::endl;
}

void call_foo(A* pa)
{
	pa->foo(); // ポインターを使ってメンバーにアクセス
	(*pa).foo();
}

int main()
{
	A a;
	call_foo(&a);

	return 0;
}
