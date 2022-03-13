#include <iostream>

class C
{
private:
	int a;

public:
	explicit C(int a) : a{a}
	{
	}

	// constメンバー関数なのでメンバー関数は変更できない
	void copy_and_set(int value) const
	{
		std::cout << "copy_and_set: a == " << a << std::endl;

		[*this, value]() mutable // thisが指し示す先のインスタンスをまるごとコピー
		{
			std::cout << "lambda: a == " << a << std::endl;
			a = value; // OK。ただし、aはコピーされたインスタンスのaを変更する
			std::cout << "lambda: a == " << a << std::endl;
		}();

		std::cout << "copy_and_set: a == " << a << std::endl;
	}
};

int main()
{
	C c{42};
	c.copy_and_set(0);

	return 0;
}
