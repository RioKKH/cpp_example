#include <iostream>

int show()
{
	return 43;
}

int main()
{
	int (*func)() = &show;

	std::cout << "show(): " << func() << std::endl;

	return 0;
}
