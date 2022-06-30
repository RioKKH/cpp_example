#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <iostream>
#include <vector>
// #include <cstdlib>
#include <string>

class Parameters
{
private:
	std::string PATH;
	std::vector<double> X;
	std::vector<double> Y;
	std::vector<double> Z;
	const char *pENV;

public:
	explicit Parameters();
	explicit Parameters(std::string PATH);
	~Parameters();

	// void setX(std::vector<double>);
	// void setY(std::vector<double>);
	// void setZ(std::vector<double>);

	void loadParams();
	// std::vector<double> getX();
	// std::vector<double> getY();
	// std::vector<double> getZ(); 

	void getEnv();
	void show() const;
};

#endif // PARAMETERS_HPP
