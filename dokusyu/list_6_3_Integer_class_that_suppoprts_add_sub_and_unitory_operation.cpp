#include <iostream>

class Integer
{
private:
	int value;

public:
	Integer() {}

	~Integer() {}

	Integer(int value) : value{value}
	{
	}

	Integer operator+(const Integer& rhs) const; // 加算
	Integer operator-(const Integer& rhs) const; // 減算

	Integer operator+() const; // 符号を変えない
	Integer operator-() const; // 符号を変える

	void show() const;
};

Integer Integer::operator+(const Integer& rhs) const
{
	return Integer{value + rhs.value};
}

Integer Integer::operator-(const Integer& rhs) const
{
	return Integer{value - rhs.value};
}

Integer Integer::operator+() const
{
	return *this;
}

Integer Integer::operator-() const
{
	return Integer{-value};
}

void Integer::show() const
{
	std::cout << "Integer.value = " << value << std::endl;
}


int main()
{
	Integer x = 10;
	Integer y = 3;
	Integer z = 7;

	auto v = x - -y + +z;
	v.show();

	auto v1 = - x; // ユニタリーオペレータでも間にスペースを入れても良い
	v1.show(); // -10
}
