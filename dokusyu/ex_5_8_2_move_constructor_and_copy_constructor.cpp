#include <iostream>
#include <utility>

class A
{
public:
	// 何かしらのコンストラクターが定義されると
	// デフォルトコンストラクターは自動生成されないので定義する
	A()
	{
	}

	A(const A& other)
	{
		std::cout << "コピーコストラクター" << std::endl;
	}

	A(A&& other)
	{
		std::cout << "ムーブコンストラクター" << std::endl;
	}
};

int main()
{
	A a;
	std::cout << "a: " << &a << std::endl;

	A c(a); // コピー
	std::cout << "c: " << &c << std::endl;

	A m(std::move(a)); // ムーブ
	std::cout << "a: " << &a << std::endl;
	std::cout << "m: " << &m << std::endl;

	return 0;
}
