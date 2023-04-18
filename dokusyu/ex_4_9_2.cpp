#include <iostream>

void foo()
{
	std::cout << "foo" << std::endl;
}

void bar()
{
	std::cout << "bar" << std::endl;
}

int main()
{
	foo();

#define foo bar

	foo();

#undef foo

	foo();

	return 0;
}
