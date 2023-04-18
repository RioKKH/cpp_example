#include <iostream>

class Base
{
private:

public:
	Base()
	{
		std::cout << "Baseコンストラクター" << std::endl;
	}

	~Base()
	{
		std::cout << "Baseデストラクター" << std::endl;
	}
};


class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Derivedコンストラクター" << std::endl;
	}

	~Derived()
	{
		std::cout << "Derived destructor" << std::endl;
	}
};


class MoreDerived : public Derived
{
public:
	MoreDerived()
	{
		std::cout << "MoreDerived constructor" << std::endl;
	}

	~MoreDerived()
	{
		std::cout << "MoreDerived destructor" << std::endl;
	}
};


int main()
{
	MoreDerived more_derived;
	std::cout << "オブジェクト構築完了" << std::endl;

	return 0;
}
