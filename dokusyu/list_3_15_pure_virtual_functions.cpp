#include <iostream>

// 面積やしゅういちょうといったものは、三角形・四角形・円
// ですべて計算方法が違うので規定くらすで共通化できない
class Shape
{
public:
	virtual float area() const = 0; // 面積を求める純粋仮想関数
	virtual float perimeter() const = 0; // 周囲長を求める純粋仮想関数
};

// 純粋仮想関数は関数本体をもたないので、メンバー関数の定義はない
// 長方形を扱うクラス
class Rectangle : public Shape
{
private:
	float height;
	float width;

public:
	explicit Rectangle(float height, float width);
	float area() const override;
	float perimeter() const override;
};

Rectangle::Rectangle(float height, float width)
	: height(height), width(width)
{
}

float Rectangle::area() const
{
	return height * width;
}

float Rectangle::perimeter() const
{
	return 2 * (height + width);
}


class Circle : public Shape
{
private:
	float r;

public:
	explicit Circle(float r);
	float area() const override;
	float perimeter() const override;
};

Circle::Circle(float r) : r(r)
{
}

float Circle::area() const
{
	return r * r * 3.14f;
}

float Circle::perimeter() const
{
	return 2 * r * 3.14f;
}

int main()
{
	Rectangle rect(10, 2);
	std::cout << "rect" << std::endl;
	std::cout << " Area:: " << rect.area() << std::endl;
	std::cout << " Perimeter: " << rect.perimeter() << std::endl;
}

