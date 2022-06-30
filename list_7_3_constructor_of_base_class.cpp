#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base default constructor" << std::endl;
	}

	explicit Base(int i)
	{
		std::cout << "Base constructor with argument: " << i << std::endl;
	}
};


class Derived : public Base
{
public:
	explicit Derived(int i) : Base{i} // 基底クラスコンストラクターの呼び出し
	{
	}
};

int main()
{
	Derived derived{42};
}
