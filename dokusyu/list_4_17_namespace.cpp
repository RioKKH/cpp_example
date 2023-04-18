#include <iostream>

namespace A
{
	struct S // 名前空間Aの構造体S
	{
		int a;
	};

	void foo() // 名前空間Aの関数foo()
	{
		std::cout << "A::foo()" << std::endl;
	}
}

namespace B
{
	struct S // 名前空間Bの構造体S
	{
		int b;
	};

	void foo() // 名前空間Bの関数foo()
	{
		std::cout << "B::foo()" << std::endl;
	}
}

int main()
{
	A::foo(); // namespace Aにある関数foo()
	B::foo(); // namespace Bにある関数foo()
	A::S as; // 名前空間Aの構造体S
	B::S bs; // 名前空間Bの構造体S
	// as = bs; // エラー。名前空間がことなるので、別の方として扱われる。
}

