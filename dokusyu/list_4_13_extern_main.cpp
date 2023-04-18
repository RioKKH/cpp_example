#include <iostream>

// 変数は宣言とどうじに暗黙的に定義がされるが、extern変数を使うと宣言飲みになる
extern int value; // extern 変数
void show_extern_variable(); // 他のファイルの関数の宣言

int main()
{
	std::cout << "main: extern変数のアドレス: " << &value << std::endl;
	std::cout << "main: extern変数の値: " << value << std::endl;

	value = 0;
	show_extern_variable();
}
