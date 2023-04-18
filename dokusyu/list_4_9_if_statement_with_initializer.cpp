#include <iostream>

// C++17
int foo(int value)
{
	std::cout << "foo: " << value << std::endl;
	return value;
}

bool is_even(int value) // 偶数ならtrueを返す関数
{
	return value % 2 == 0;
}

bool is_zero(int value)
{
	return value == 0;
}

int main()
{
	if (int result = foo(42); is_even(result) && !is_zero(result))
	{
		std::cout << "foo(42)はゼロではない偶数を返しました" << std::endl;
	}
	return 0;
}
