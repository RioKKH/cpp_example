#include <iostream>

class Base
{
private:
	int value = 0;

public:
	void set_value(int value);
	int get_value() const;
};

void Base::set_value(int value)
{
	// メンバー変数名と仮引数名が同じためthis ポインターを用いている
	this->value = value;
}

int Base::get_value() const
{
	return value;
}

// 構造体がくらすから派生することもできる
// デフォルトのアクセス指定子はpublic
struct Derived : Base
{
	Derived();
	~Derived();
};

Derived::Derived()
{
	std::cout << "constructor" << std::endl;
}

Derived::~Derived()
{
	std::cout << "destructor" << std::endl;
}

int main()
{
	Derived d;

	std::cout << d.get_value() << std::endl;
	d.set_value(42);
	std::cout << d.get_value() << std::endl;
}

