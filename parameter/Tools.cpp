#include <iostream>
#include <string>
#include <vector>
#include <sstream> // std::stringstream
#include <istream> // std::getline

std::vector<std::string> split(std::string line, char del = ',')
{
	int first = 0;
	int last = line.find_first_of(del);
	std::vector<std::string> result;

	while (first < int(line.size()))
	{
		result.push_back(line.substr(first, last - first));
		first = last + 1;
		last = line.find_first_of(del, first);
		if (last == int(std::string::npos))
		{
			last = line.size();
		}
	}
	return result;
}

