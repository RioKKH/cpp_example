#include <iostream>
#include <random>

int main()
{
	std::mt19937 mt(1);
	std::uniform_int_distribution<> prng(0, 9);
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; ++i)
	{
		std::cout << (a[i] + prng(mt)) % 10 << std::endl;
	}
}
