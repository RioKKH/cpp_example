#include <iostream>

class A
{
private:

public:
	A();
	explicit A(int value);
	explicit A(int value1, int value2);
	~A();

	void show_value() const;
};

A::A()
{
	std::cout << "A::A()" << std::endl;
}

A::A(int value)
{
	std::cout << "A::A(" << value << ")" << std::endl;
}

A::A(int value1, int value2)
{
	std::cout << "A::A(" << value1 << ", " << value2 << ")" << std::endl;
}

A::~A()
{
	std::cout << "deconstructor" << std::endl;
}


int main()
{

	A* ptr1 = new A{};

	delete ptr1;

	A* ptr2 = new A{42};

	delete ptr2;

	A* ptr3 = new A{42, 43};

	delete ptr3;

	return 0;
}


