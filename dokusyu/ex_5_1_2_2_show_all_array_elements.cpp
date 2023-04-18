#include <iostream>

int main()
{
	int array[] = {0, 1, 2, 3, 4};

	for (int* ptr = array; ptr != (array + 5); ++ptr)
	{
		std::cout << *ptr << std::endl;
	}

	return 0;
}

