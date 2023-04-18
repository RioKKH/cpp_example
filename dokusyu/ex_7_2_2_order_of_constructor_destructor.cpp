#include <iostream>

class Base
{
public:
	explicit Base(int value)
	{
		std::cout << "Base(" << value << ")" << std::endl;
	}
};

class Derived : public Base
{
public:
	Derived() : Base{0} // 基底クラスのコンストラクター呼び出し
	{
	}
};

int main()
{
	Derived derived{};
}
