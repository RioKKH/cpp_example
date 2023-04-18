#include <iostream>

int main()
{
	int array[] = {0, 1, 2, 3};

	int* ptr = array;

	ptr += 2; // 2番目のアドレス
	std::cout << *ptr << std::endl;

	++ptr; // 3番めのアドレス
	std::cout << *ptr << std::endl;

	ptr -= 2; // 1番目のアドレス
	std::cout << *ptr << std::endl;

	--ptr; // 0番目のアドレス
	std::cout << *ptr << std::endl;
}
