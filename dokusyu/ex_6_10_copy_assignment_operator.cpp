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

    Float& operator = (const Float& rhs);

	Float& operator += (const Float& rhs);
	Float& operator -= (const Float& rhs);
	Float& operator *= (const Float& rhs);
	Float& operator /= (const Float& rhs);

	// Float operator + (const Float& rhs) const;
	friend Float operator + (const Float&, float);
	friend Float operator + (float, const Float&);

	// Float operator - (const Float& rhs) const;
	friend Float operator - (const Float&, float);
	friend Float operator - (float, const Float&);
	
	// Float operator * (const Float& rhs) const;
	friend Float operator * (const Float&, float);
	friend Float operator * (float, const Float&);

	// Float operator / (const Float& rhs) const;
	friend Float operator / (const Float&, float);
	friend Float operator / (float, const Float&);

	void show() const;
};

Float& Float::operator = (const Float& rhs)
{
	value = rhs.value;
	return *this;
}

Float& Float::operator += (const Float& rhs)
{
	value += rhs.value;
	return *this;
}

Float& Float::operator -= (const Float& rhs)
{
	value -= rhs.value;
	return *this;
}

Float& Float::operator *= (const Float& rhs)
{
	value *= rhs.value;
	return *this;
}

Float& Float::operator /= (const Float& rhs)
{
	value /= rhs.value;
	return *this;
}

Float operator+(const Float& lhs, float rhs)
// Float Float::operator+(const Float& rhs) const
{
	return Float{lhs.value + rhs};
}

Float operator+(float lhs, const Float& rhs)
// Float Float::operator+(const Float& rhs) const
{
	return Float{lhs + rhs.value};
}

Float operator-(const Float& lhs , float rhs)
// Float Float::operator-(const Float& rhs) const
{
	return Float{lhs.value - rhs};
}

Float operator-(float lhs, const Float& rhs)
// Float Float::operator-(const Float& rhs) const
{
	return Float{lhs - rhs.value};
}

Float operator*(const Float& lhs, float rhs)
// Float Float::operator*(const Float& rhs) const
{
	return Float{lhs.value * rhs};
}

Float operator*(float lhs, const Float& rhs)
// Float Float::operator*(const Float& rhs) const
{
	return Float{lhs * rhs.value};
}

Float operator/(const Float& lhs, float rhs)
// Float Float::operator/(const Float& rhs) const
{
	return Float{lhs.value / rhs};
}

Float operator/(float lhs, const Float& rhs)
// Float Float::operator/(const Float& rhs) const
{
	return Float{lhs / rhs.value};
}

void Float::show() const
{
	std::cout << "Float.value = " << value << std::endl;
}


int main()
{
	Float ten{10};
	auto result = 1 + ten - 8;
	result.show();

	auto result2 = ten * 8;
	result2.show();

	return 0;
}

