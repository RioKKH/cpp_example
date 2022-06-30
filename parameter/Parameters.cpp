#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "Parameters.hpp"
#include "Tools.hpp"

Parameters::Parameters()
{
	std::cout << "Constructor of Parameters" << std::endl;
}

Parameters::Parameters(std::string PATH)
{
	std::cout << "Constructor of Parameters" << std::endl;
}

Parameters::~Parameters()
{
	std::cout << "Destructor of Parameters" << std::endl;
}

// std::vector<double> getX()
// {
// }
// 
// std::vector<double> getY()
// {
// }
// 
// std::vector<double> getZ()
// {
// }

void Parameters::loadParams()
{
	const std::string INFILE = "/home/kakehi/work/git/cpp_example/parameter/test.prms";
	std::ifstream infile(INFILE);
	std::string line;
	// std::smatch results;
	std::vector<std::string> result;

	while (getline(infile, line))
	{
		result = split(line, ',');
		int size = int(result.size());

		if (result[0] == "X")
		{
			for (int i = 1; i < size; ++i)
			{
				X.push_back(std::stod(result[i]));
			}
		}
		else if (result[0] == "Y")
		{
			for (int i = 1; i < size; ++i)
			{
				Y.push_back(std::stod(result[i]));
			}
		}
		else if (result[0] == "Z")
		{
			for (int i = 1; i < size; ++i)
			{
				Z.push_back(std::stod(result[i]));
			}
		}
	}
	infile.close();
	return;
}

void Parameters::getEnv() {
	pENV = std::getenv("HOME");
	// pENV = std::getenv("EOSHOME");
	if (pENV != nullptr)
	{
		std::cout << pENV << std::endl;
	}
}

void Parameters::show() const
{
	std::cout << "Hi, I am Parameters!" << std::endl;
	std::cout << "HOME: " << pENV << std::endl;
	for (const auto& x : X) { std::cout << x << " "; } std::cout << std::endl;
	for (const auto& y : Y) { std::cout << y << " "; } std::cout << std::endl;
	for (const auto& z : Z) { std::cout << z << " "; } std::cout << std::endl;
}
