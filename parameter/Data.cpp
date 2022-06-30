#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Data.hpp"
#include "Tools.hpp"

Data::Data()
{
}

Data::~Data()
{
	std::cout << "Destructor of Data" << std::endl;
}

void Data::loadData()
{
	const std::string INFILE = "/home/kakehi/work/git/cpp_example/parameter/data.dat";
	std::ifstream infile(INFILE);
	std::string line;
	std::vector<std::string> result;

	int lineIdx = 0;
	while (getline(infile, line))
	{
		if (lineIdx < 2)
		{
			// write any code if needed.
		}
		else
		{
			result = split(line, ',');
			int size = int(result.size());
			for (int i = 0; i < size; ++i)
			{
				vX.push_back(std::stoi(result[i]));
				vY.push_back(std::stoi(result[i]));
				v.push_back(std::stoi(result[i]));
				v.push_back(std::stod(result[i]));
				v.push_back(std::stod(result[i]));
				v.push_back(std::stod(result[i]));
				v.push_back(std::stod(result[i]));
				v.push_back(std::stod(result[i]));
			}
			std::cout << std::endl;
		}
		++lineIdx;
	}
}

void Data::getEnv()
{
}

void Data::show() const
{
	std::cout << "Data::show()" << std::endl;
}

