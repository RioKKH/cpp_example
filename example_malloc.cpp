#include <iostream>
#include <stdlib.h>

int simple(void);
int reallocate(void);

int simple() 
{
	int *p = (int *)malloc(sizeof(int) * 10);
	if (p == NULL) {
		std::cout << "Memory cannot be allocated." << std::endl;
	} else {
		std::cout
			<< "Memory has been allocated. The address is"
			<< p << std::endl;
	}
	free(p);
	return 0;
}

int reallocate()
{
	int *p = (int *)malloc(sizeof(int) * 10);
	if (p == NULL) {
		std::cout << "Memory cannot be allocated." << std::endl;
	} else {
		std::cout
			<< "Memory has been allocated. The address is "
			<< p << std::endl;
	}

	int *q  = (int *)realloc(p, sizeof(int) * 20);
	if (q == NULL) {
		std::cout << "Memory cannot be enlarged." << std::endl;
	} else {
		std::cout << "Memory has been enlarged. The new address is "
			<< q << std::endl;
	}

	free(q);

	return 0;
}

int main(int argc, char const* argv[])
{
	return reallocate();
}
