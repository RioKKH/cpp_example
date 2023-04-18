#include <iostream>

class Integer
{
private:
	int value;

public:
	Integer(int value) : value{value}
	{
	}

	Integer& operator = (const Integer& rhs);
	void show() const;
};

// コピー代入演算子はコピー元のオブジェクトを変更できないので
// const 参照で受け取る
Integer& Integer::operator = (const Integer& rhs)
{
	std::cout << "コピー: " << value << " -> " << rhs.value << std::endl;
	value = rhs.value; // 値をコピーする
	return *this;
}

void Integer::show() const
{
	std::cout << "value: " << value << std::endl;
}

int main()
{
	Integer x = 42;
	Integer y = 10;

	std::cout << "address of y: " << &y << std::endl;
	y = x; // copy
	y.show();
	std::cout << "address of x: " << &x << std::endl;
	std::cout << "address of y: " << &y << std::endl;

	return 0;
}
