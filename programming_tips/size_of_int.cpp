#include <iostream>
#include <limits>

int main(int argc, char* argv[])
{
	std::cout << sizeof(int) << "\n";

	int x{};
	std::cout << sizeof(x) << std::endl;

	auto print = [](std::size_t s)
	{
		std::cout << s << "\n";
	};

	print(sizeof(char));
	print(sizeof(short));
	print(sizeof(int));
	print(sizeof(long));
	print(sizeof(long long));

	std::cout
		<< std::numeric_limits<int>::min() << "\n"
		<< std::numeric_limits<int>::max() << std::endl;
}
