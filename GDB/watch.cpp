#include <iostream>

template <typename T>
void replace(T& a, T b)
{
	a = b;
	return;
}

int main(int argc, char** argv)
{
	int a = 10;
	std::cout << a << std::endl;
	replace(a, 15);
	std::cout << a << std::endl;
	replace(a, 20);
	std::cout << a << std::endl;

	return 0;
}

