#include <iostream>
#include "test.hpp"

int main()
{
	A a{1, 1};
	A b{2, 2};
	A c{0, 0};
	a.show();
	b.show();
	c.show();

	a.load();
	b.load();

	// a.show(); // 1 and 2
	// a + b;
	// a.show(); // 2 and 4
	// b.show(); // 1 and 2
	// a + b;
	// A c = a + b;
	
	c.show();
	c = a + b;
	std::cout << "C: " << std::endl;
	c.show();
	std::cout << "A: " << std::endl;
	a.show();
	std::cout << "B: " << std::endl;
	b.show();

	return 0;
}

