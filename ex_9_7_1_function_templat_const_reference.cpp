#include <iostream>

// 常にconst参照で引数を受け取る関数テンプレート
template <typename T>
void show_value(const T& value)
{
	std::cout << value << std::endl;
}

int main()
{
	const int i = 42;
	show_value(i);

	return 0;
}
