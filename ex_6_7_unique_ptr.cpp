#include <iostream>
#include <memory>

class A
{
public:
	A()
	{
		std::cout << "constructor" << std::endl;
	}

	~A()
	{
		std::cout << "destructor" << std::endl;
	}
};

int main()
{
	auto ptr = std::make_unique<A>();
}
