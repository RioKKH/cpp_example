#include <iostream>

class Integer
{
private:
	int value;

public:
	Integer(int value) : value{value}
	{
	}

	bool operator == (int a, int b) const;
	bool operator != (int a, int b) const;
	bool operator <= (int a, int b) const;
	bool operator > (int a, int b) const;
	bool operator >= (int a, int b) const;
};

bool Integer::operator == (int a, int b) const
{
	return !(a < b) && !(b < a);
}

bool Integer::operator != (int a, int b) const
{
	return (a < b) || (b < a);
}

bool Integer::operator <= (int a, int b) const
{
	return !(b < a);
}

bool Integer::operator >= (int a, int b) const
{
	return !(a < b);
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
}

