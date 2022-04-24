#include <iostream>

// forwarding references
// フォワーディング参照は右辺値参照とテンプレートを組み合わせたたときに
// 特別な動作をする参照のこと

// 左辺値を受け取るテンプレート
template <typename T>
void foo(T& value)
{
	std::cout << "void foo(T& value)" << std::endl;
}

// 右辺値を受け取るテンプレート
template <typename T>
void foo(T&& value)
{
	std::cout << "void foo(T&& value)" << std::endl;
}

int main()
{
	int i = 0;

	foo(i);
	foo(0);

	return 0;
}
