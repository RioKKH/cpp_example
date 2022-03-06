#include <iostream>

int main()
{
	int array[] = {0, 1, 2, 3, 4};
	int* ptr = array;

	for (int i=0; i<5; ++i)
	{
		std::cout << *ptr++ << std::endl;
	}

	return 0;
}

