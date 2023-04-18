#include <iostream>

class Base
{
private:

public:
	void foo();
};

void Base::foo()
{
	std::cout << "Base::foo()" << std::endl;
}

class Derived : public Base
{
private:

public:
	// overrideせず、規定クラスのBase.foo()そのものを呼び出したい場合
	// 名前の隠蔽が起きてしまうので、派生クラス側でusing 宣言を用いて
	// 規定くらすのメンバー関数をオーバーロードとして追加する
	using Base::foo; // 規定クラスのfoo()を呼び出せるようにする
	void foo(int v); // 派生クラスで追加したオーバーロード
};

void Derived::foo(int v)
{
	std::cout << "Derived::foo(" << v<< ")" << std::endl;
}

int main()
{
	Derived derived;
	derived.foo();
	derived.foo(42);
}
