#include <iostream>

void show(int& v)
{
	std::cout << "参照: " << v << std::endl;
}

// 右辺値参照は通常の参照とは異なり、オーバーロードすることができる
void show(int&& v) // 右辺値参照で受け取るオーバーロード
{
	std::cout << "右辺値参照: " << v << std::endl;
	v = 43;
	std::cout << "右辺値参照: " << v << std::endl;
}

int main()
{
	int v = 1;
	show(v); // 変数は左辺値
	show(42); // 数値は右辺値
}
