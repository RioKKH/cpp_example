#include <iostream>

// reverse関数をここに定義する
void reverse(int* aptr, int size)
{
	for (int i=0; i<size/2; ++i)
	{
		int tmp = aptr[i];
		aptr[i] = aptr[size-i-1];
		aptr[size-i-1] = tmp;
	}
}

int main()
{
	int array[] = {0, 1, 2, 3, 4};

	reverse(array, 5); // 引数は配列とその長さ

	std::cout << array[0] << std::endl;
	std::cout << array[1] << std::endl;
	std::cout << array[2] << std::endl;
	std::cout << array[3] << std::endl;
	std::cout << array[4] << std::endl;

	return 0;
}

