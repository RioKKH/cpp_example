#include <iostream>

class Base
{
public:
	// 仮想関数 virtual functions
	virtual void foo(); // 派生クラスで書き換えるサイン
};

void Base::foo() // 定義にはvirtualは書かない
{
	std::cout << "Base::foo():" << std::endl;
}

class Derived : public Base
{
public:
	void foo() override; // 派生くらすでメンバー関数をoverride
	// void foo(int i) override; // エラー。対応する仮想関数が規定クラスにない
	void foo(int i); // OK。単なるオーバーロードは追加できる
};

void Derived::foo() // 定義にoverrideは書かない
{
	std::cout << "Derived:foo() override" << std::endl;
}

void Derived::foo(int i)
{
	std::cout << "Derived::foo(int)" << std::endl;
}

int main()
{
	Derived derived;
	derived.foo();
	derived.foo(42);
}

