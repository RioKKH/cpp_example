#include <iostream>

class Float
{
private:
	float value = 0.0f;

public:
	Float()
	{
	}

	~Float()
	{
	}

	Float(float value) : value{value}
	{
	}

	Float operator + (const Float& rhs) const;
	Float operator - (const Float& rhs) const;
	Float operator * (const Float& rhs) const;
	Float operator / (const Float& rhs) const;

	const Float& operator+() const;
	Float operator-() const;

	void show() const;
};


Float Float::operator+(const Float& rhs) const
{
	return Float{value + rhs.value};
}

Float Float::operator-(const Float& rhs) const
{
	return Float{value - rhs.value};
}

Float Float::operator*(const Float& rhs) const
{
	return Float{value * rhs.value};
}

Float Float::operator/(const Float& rhs) const
{
	return Float{value / rhs.value};
}

const Float& Float::operator+() const
{
	return *this;
}

Float Float::operator-() const
{
	return Float{-value};
}

void Float::show() const
{
	std::cout << "Float.value = " << value << std::endl;
}


int main()
{
	Float x = 1.5;
	Float y = 3.2;

	auto v1 = x + y;
	v1.show();

	auto v2 = x - y;
	v2.show();

	auto v3 = x * y;
	v3.show();

	auto v4 = x / y;
	v4.show();

	auto v5 = +x;
	v5.show();

	auto v6 = -x;
	v6.show();
}

