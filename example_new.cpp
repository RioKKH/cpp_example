#include <iostream>
#include <memory>

int main(int argc, char const* argv[])
{
	int *p = nullptr;
	try {
		p = new int[10];
		std::cout << p << std::endl;
	} catch (const std::bad_alloc& e) {
		std::cout << "Cannot be allocated." << std::endl;
	}

	delete p;

	return 0;
}
