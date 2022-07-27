#include <sstream>
#include <iostream>
#include <vector>

template <typename Iter>
std::string join(Iter begin, Iter end, std::string const& separator)
{
	std::ostringstream result;
	if (begin != end)
	{
		result << *begin++;
	}
	while (begin != end)
	{
		result << separator << *begin++;
	}
	return result.str();
}

int main()
{
	std::vector<int> a{1, 2, 3, 4, 5};
	std::string a_con = join(a.begin(), a.end(), "_");
	std::cout << a_con << std::endl;
}

