#include <iostream>

class Marker
{
public:
	Marker();
	~Marker();
};

Marker::Marker()
{
	std::cout << "constructor: " << this << std::endl;
}

Marker::~Marker()
{
	std::cout << "destructor: " << this << std::endl;
}

void copy(Marker m)
{
	std::cout << "copy: " << &m << std::endl;
}

void reference(const Marker &m)
{
	std::cout << "reference: " << &m << std::endl;
}

int main()
{
	Marker m;

	std::cout << "Before call by value" << std::endl;
	copy(m);
	std::cout << "After call by value" << std::endl;

	std::cout << "Before call by reference" << std::endl;
	reference(m);
	std::cout << "After call by reference" << std::endl;

	return 0;
}
