#include <iostream>

class Integer
{
private:
	int value;

public:
	Integer(int value) : value{value}
	{
	}

	/*
	 * 二項演算子の場合には元のオブジェクトには変更を加えず
	 * 計算した結果を新しいオブジェクトとして返す
	 *
	 * 複合代入演算子の場合には代入までおこなうので、const
	 * メンバー関数には出来ず、自分自身を返す
	 */
	Integer& operator += (const Integer& rhs); // 加算
	Integer& operator -= (const Integer& rhs); // 減算
	Integer& operator *= (const Integer& rhs); // 乗算
	Integer& operator /= (const Integer& rhs); // 除算

	void show() const;
};

Integer& Integer::operator += (const Integer& rhs)
{
	value += rhs.value;
	return *this;
}

Integer& Integer::operator -= (const Integer& rhs)
{
	value -= rhs.value;
	return *this;
}

Integer& Integer::operator *= (const Integer& rhs)
{
	value *= rhs.value;
	return *this;
}

Integer& Integer::operator /= (const Integer& rhs)
{
	value /= rhs.value;
	return *this;
}

void Integer::show() const
{
	std::cout << "Ingeger.value = " << value << std::endl;
}

int main()
{
	Integer x = 10;
	Integer y = 3;
	Integer z = 7;

	z *= x;
	y /= y;
	x -= y;
	x += z;

	x.show();
	y.show();
	z.show();

	return 0;
}

