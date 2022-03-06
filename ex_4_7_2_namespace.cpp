#include <iostream>

void foo()
{
	std::cout << "foo in global namespace" << std::endl;
}

namespace module
{
	void foo()
	{
		std::cout << "foo() in module" << std::endl;
	}
}

int main()
{
	// foo();
	using module::foo;
	foo();

	return 0;
}
