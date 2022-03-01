#include <iostream>

class Base
{
public:
	void foo();
};

void Base::foo()
{
	std::cout << "foo()" << std::endl;
}

class Derived : public Base // Base のメンバーを継承する
{
public:
	void bar(); // 派生クラスで追加した機能
};

void Derived::bar()
{
	std::cout << "bar()" << std::endl;
}

int main()
{
	Base base;
	base.foo();
	// base.bar() // エラー

	Derived derived;
	derived.foo();
	derived.bar();
}
