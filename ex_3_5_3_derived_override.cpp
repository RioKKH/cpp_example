#include <iostream>

class Base
{
public:
	virtual std::string name() const;
	virtual std::string most_name() const = 0;
};

std::string Base::name() const
{
	return "Base";
}


class Derived : public Base
{
public:
	std::string name() const override;
};

std::string Derived::name() const
{
	return "Derived";
}


class MoreDerived : public Derived
{
public:
	std::string name() const override;
	std::string most_name() const override;
};

std::string MoreDerived::name() const
{
	return "MoreDerived";
}

std::string MoreDerived::most_name() const
{
	return "MoreDerived most_name";
}

int main()
{
	// Base b; // error since Base has pure virtual function.
	// std::cout << b.name() << std::endl;

	// Derived d;
	// std::cout << d.name() << std::endl;

	MoreDerived m;
	std::cout << m.name() << std::endl;
	std::cout << m.most_name() << std::endl;

	return 0;
}
