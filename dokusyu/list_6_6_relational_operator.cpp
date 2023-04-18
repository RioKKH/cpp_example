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
	bool operator < (const Integer& rhs) const;
	bool operator > (const Integer& rhs) const;
	bool operator <= (const Integer& rhs) const;
	bool operator >= (const Integer& rhs) const;
};

bool Integer::operator == (const Integer& rhs) const
{
	return value == rhs.value;
}

bool Integer::operator != (const Integer& rhs) const
{
	// == を呼び出してその否定を返す
	return !(*this == rhs);
}

bool Integer::operator < (const Integer& rhs) const
{
	return value < rhs.value;
}

bool Integer::operator > (const Integer& rhs) const
{
	// 左右を入れ替えて、小なりを呼ぶと大なりの結果になる
	return rhs < *this;
}

bool Integer::operator <= (const Integer& rhs) const
{
	// 大なりを否定した結果が小なりイコールの結果になる
	return !(rhs < *this);
}

bool Integer::operator >= (const Integer& rhs) const
{
	// 左右を入れ替えて小なりイコールを呼ぶと
	// 大なりイコールの結果になる。
	return rhs <= *this;
}

int main()
{
	Integer x = 10;
	Integer y = 3;

	if (x == y)
	{
		std::cout << "x == y is true" << std::endl;
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
		std::cout << "x != y is false" << std::endl;
	}
	std::cout << std::endl;

	if (y <= x)
	{
		std::cout << "y <= x is true" <<std::endl;
	}
	else
	{
		std::cout << "y <= x is false" << std::endl;
	}

	if (y >= x)
	{
		std::cout << "y >= x is true" << std::endl;
	}
	else
	{
		std::cout << "y >= x is false" << std::endl;
	}
}
