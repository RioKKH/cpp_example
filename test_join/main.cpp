#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Tools.hpp"

int main()
{
	std::vector<int> a{1, 2, 3, 4, 5};
	for (const auto& aa : a)
	{
		std::cout << aa << " ";
	}
	std::cout << std::endl;

	std::string filename = join(a.begin(), a.end(), "_");
	std::cout << filename << std::endl;

	return 0;
}
