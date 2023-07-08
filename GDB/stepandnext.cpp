#include <iostream>

void printFoo(void)
{
	std::cout << "Foo" << std::endl;
	return;
}

void printBar(void)
{
	std::cout << "Bar" << std::endl;
	return;
}

int main(int argc, char** argv)
{
	printFoo();
	printBar();

	return 0;
}

