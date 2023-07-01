#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	if (std::string(argv[1]) == "foo")
	{
		std::cout << "foo!" << std::endl;
	}
	else 
	{
		std::cout << "bar!" << std::endl;
	}
	return 0;
}

