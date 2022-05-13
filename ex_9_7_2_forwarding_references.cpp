#include <iostream>

// フォワーディング参照を使った関数テンプレート
// 左辺値と右辺値の両方を受け取れる関数テンプレート
template <typename T>
void show_value(T&& value)
{
	std::cout << value << std::endl;
}
int main()
{
	const int i = 42;
	show_value(i);
	show_value(2.718);

	return 0;
}
	
