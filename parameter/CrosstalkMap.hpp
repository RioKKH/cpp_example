#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>
#include <string>

//typedef struct {
//} stXtalkData;
//stXtalkData stxtalkdata; 


typedef struct _data {
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
} Data;


class CrosstalkMap
{
private:
    const std::string FILENAME = "data.dat";
    std::string CWD;

	std::vector<int> invalidx;
	std::vector<int> invalidy;

	Data raw; 
	Data trimmed;

public:
	explicit CrosstalkMap();
	~CrosstalkMap();

	void loadData();
	void show_raw_data() const;
	void show_trimmed_data() const;

	void getFourCorners();
	void trimData();
	void shift();
};

#endif // MAP_HPP
