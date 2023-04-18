#include <iostream>

class Integer
{
private:
	int value;

public:
	explicit Integer(int value) : value{value}
	{
	}

	// インスタンスが演算子の左側にあるので
	// メンバー関数で実装することも出来る
	friend Integer operator + (const Integer&, int);

	// インスタンスが演算子の右側にあるので
	// メンバー関数では実装出来ない
	friend Integer operator + (int, const Integer&);

	friend Integer operator - (const Integer&, int);
	friend Integer operator - (int, const Integer&);

	void show() const;
};

Integer operator + (const Integer& lhs, int rhs)
{
	// フレンド関数なので、プライベートメンバーにアクセス出来る
	return Integer{lhs.value + rhs};
}

// Integerのインスタンスが右辺に来る+はこのオーバーロードが使用される
Integer operator + (int lhs, const Integer& rhs)
{
	return Integer{lhs + rhs.value};
}

Integer operator - (const Integer& lhs, int rhs)
{
	return Integer{lhs.value - rhs};
}

Integer operator - (int lhs, const Integer& rhs)
{
	return Integer{lhs - rhs.value};
}

void Integer::show() const
{
	std::cout << "value: " << value << std::endl;
}

int main()
{
	Integer ten{10};
	Integer result = 1 + ten - 8;
	result.show();

	return 0;
}

