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
	foo();
	module::foo();

	return 0;
}
