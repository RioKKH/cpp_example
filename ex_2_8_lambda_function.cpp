// lambda function
#include <iostream>

void show_value_org(int v)
{
	std::cout << v << std::endl;
}

auto show_value = [](int v) -> void
{
	std::cout << v << std::endl;
};

int main()
{
	show_value(42);
}
