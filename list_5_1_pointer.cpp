#include <iostream>

int main()
{
	int array[] = {0, 1, 2, 3};

	std::cout << "先頭の値:" << array[0] << std::endl;
	std::cout << "先頭のアドレス:" << &array[0] << std::endl;

	std::cout << std::endl;

	int* ptr = array; // 配列からポインターへの暗黙変換
	
	std::cout << "ポインター" << ptr << std::endl;
	std::cout << "値:" << *ptr << std::endl;

	std::cout << std::endl;

	const char* string = "string literal";
	std::cout << "文字列リテラル: " << string << std::endl;
	std::cout << "文字列リテラルアドレス: " << &string << std::endl;

	return 0;
}

