#include <iostream>

int main()
{
	int&& i = 1; // 1への右辺値参照
	i = 0; // OKは左辺値

	if (i == 0)
	{
		std::cout << "1 == 0" << std::endl;
	}
	else
	{
		std::cout << "1 != 0" << std::endl;
	}

	return 0;
}
