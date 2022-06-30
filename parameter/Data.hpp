#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <vector>
#include <string>

//typedef struct {
//} stXtalkData;
//stXtalkData stxtalkdata; 


class Data
{
private:
	std::vector<int> vX;
	std::vector<int> vY;
	std::vector<int> vValid;
	std::vector<double> vX0;
	std::vector<double> vY0;
	std::vector<double> va;
	std::vector<double> vb;
	std::vector<double> vTh;
	std::vector<double> vNumOfPixel;
	std::vector<double> vAverage;
	std::vector<double> vMode;
	std::vector<double> vMax;
                       
public:
	explicit Data();
	~Data();

	void loadData();
	void getEnv();
	void show() const;

};

#endif // DATA_HPP
