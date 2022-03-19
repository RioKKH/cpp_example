#include <iostream>

class Integer
{
private:
	int value;

public:
	Integer(int value) : value{value}
	{
	}

	bool operator == (const Integer& rhs) const;
	bool operator != (const Integer& rhs) const;
	bool operator <= (const Integer& rhs) const;
	bool operator > (const Integer& rhs) const;
	bool operator >= (const Integer& rhs) const;
};

bool Integer::operator == (const Integer& rhs) const
{
	return !(this->value < rhs.value) && !(rhs.value < this->value);
}

bool Integer::operator != (const Integer& rhs) const
{
	return (this->value < rhs.value) || (rhs.value < this->value);
}

bool Integer::operator <= (const Integer& rhs) const
{
	return !(rhs.value < this->value);
}

bool Integer::operator >= (const Integer& rhs) const
{
	return !(this->value < rhs.value);
}

int main()
{
	Integer x = 10;
	Integer y = 3;
	Integer z = 0;

	if (x == y)
	{
		std::cout << "x == y is true." << std::endl;
	}
	else
	{
		std::cout << "x == y is false" << std::endl;
	}

	if (x != y)
	{
		std::cout << "x != y is true" << std::endl;
	}
	else
	{
		std::cout << "X != y is false" << std::endl;
	}
}

