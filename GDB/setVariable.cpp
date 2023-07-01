#include <iostream>

template <typename T>
void show(const T& a)
{
	std::cout << a << std::endl;
	return;
}

int main(int argc, char** argv)
{
	int a = 0;
	show(a);
	show(a);

	return 0;
}
