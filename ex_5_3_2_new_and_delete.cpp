#include <iostream>

class A
{
private:
	
public:
	A();
	~A();
};

A::A()
{
	std::cout << "constructor" << std::endl;
}

A::~A()
{
	std::cout << "destructor" << std::endl;
}

int main()
{
	A *a = new A{};
	// delete a;

	return 0;
}
