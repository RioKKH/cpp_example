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
            std::cout << line << std::endl;
			int size = int(result.size());
			for (int i = 0; i < size; ++i)
			{
				vX.push_back(std::stoi(result[i]));
				vY.push_back(std::stoi(result[i]));
				vValid.push_back(std::stoi(result[i]));
				vX0.push_back(std::stod(result[i]));
				vY0.push_back(std::stod(result[i]));
				va.push_back(std::stod(result[i]));
				vb.push_back(std::stod(result[i]));
				vTh.push_back(std::stod(result[i]));
				vNumOfPixel.push_back(std::stod(result[i]));
				vAverage.push_back(std::stod(result[i]));
				vMode.push_back(std::stod(result[i]));
				vMax.push_back(std::stod(result[i]));
			}
			std::cout << std::endl;
		}
		++lineIdx;
	}
}

void Data::makeFilePath()
{
    
}

void Data::show() const
{
	std::cout << "Data::show()" << std::endl;
}

void Data::showX() const
{
	std::cout << "Data::showX()" << std::endl;
    for (const auto& x : vX)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void Data::showY() const
{
	std::cout << "Data::showY()" << std::endl;
    for (const auto& y : vY)
    {
        std::cout << y << " ";
    }
    std::cout << std::endl;
}

