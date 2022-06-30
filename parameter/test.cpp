#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

int main()
{
	const std::string INFILE = "/home/kakehi/work/git/cpp_example/parameter/test.prms";
	std::ifstream infile(INFILE);
	std::string line;
	std::string elem;
	std::vector<std::string> result;
	int first, last;

	while (std::getline(infile, line))
	// while (std::getline(infile, line, ','))
	{
		first = 0;
		last = line.find_first_of(',');
		while (first < line.size())
		{
			result.push_back(line.substr(first, last - first));
			first = last + 1; 
			last = line.find_first_of(',', first);
			if (last == std::string::npos) last = line.size();
		}
	}
	for (const auto& x : result)
	{
		std::cout << x << std::endl;
	}
}

