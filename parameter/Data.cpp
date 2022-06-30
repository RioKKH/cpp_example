#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>

#include "Data.hpp"
#include "Tools.hpp"

Data::Data()
{
    char cwd[512];
    CWD = getcwd(cwd, 512);
}

Data::~Data()
{
	std::cout << "Destructor of Data" << std::endl;
}

void Data::loadData()
{
    const std::string INFILE = CWD + "/" + FILENAME;
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
            if (size == 12)
            {
                vX.push_back(std::stoi(result[0]));
                vY.push_back(std::stoi(result[1]));
                vValid.push_back(std::stoi(result[2]));
                vX0.push_back(std::stod(result[3]));
                vY0.push_back(std::stod(result[4]));
                va.push_back(std::stod(result[5]));
                vb.push_back(std::stod(result[6]));
                vTh.push_back(std::stod(result[7]));
                vNumOfPixel.push_back(std::stod(result[8]));
                vAverage.push_back(std::stod(result[9]));
                vMode.push_back(std::stod(result[10]));
                vMax.push_back(std::stod(result[11]));
            }
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
    for (const auto& x : vX) { std::cout << x << " "; } std::cout << std::endl;
    for (const auto& y : vY) { std::cout << y << " "; } std::cout << std::endl;
    for (const auto& v : vValid) { std::cout << v << " "; } std::cout << std::endl;
    for (const auto& x0 : vX0) { std::cout << x0 << " "; } std::cout << std::endl;
    for (const auto& y0 : vY0) { std::cout << y0 << " "; } std::cout << std::endl;
    for (const auto& a : va) { std::cout << a << " "; } std::cout << std::endl;
    for (const auto& b : vb) { std::cout << b << " "; } std::cout << std::endl;
    for (const auto& th : vTh) { std::cout << th << " "; } std::cout << std::endl;
    for (const auto& p : vNumOfPixel) { std::cout << p << " "; } std::cout << std::endl;
    for (const auto& A : vAverage) { std::cout << A << " "; } std::cout << std::endl;
    for (const auto& M : vMode) { std::cout << M << " "; } std::cout << std::endl;
    for (const auto& X : vMax) { std::cout << X << " "; } std::cout << std::endl;
}

void Data::showX() const
{
	std::cout << "Data::showX()" << std::endl; for (const auto& x : vX)
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
        std::cout << y << " "; }
    std::cout << std::endl;
}

