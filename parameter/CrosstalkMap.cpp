#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>

#include "CrosstalkMap.hpp"
#include "Tools.hpp"

CrosstalkMap::CrosstalkMap()
{
    char cwd[512];
    CWD = getcwd(cwd, 512);
}

CrosstalkMap::~CrosstalkMap()
{
	std::cout << "Destructor of Data" << std::endl;
}

void CrosstalkMap::loadData()
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
                raw.vX.push_back(std::stoi(result[0]));
                raw.vY.push_back(std::stoi(result[1]));
                raw.vValid.push_back(std::stoi(result[2]));
                raw.vX0.push_back(std::stod(result[3]));
                raw.vY0.push_back(std::stod(result[4]));
                raw.va.push_back(std::stod(result[5]));
                raw.vb.push_back(std::stod(result[6]));
                raw.vTh.push_back(std::stod(result[7]));
                raw.vNumOfPixel.push_back(std::stod(result[8]));
                raw.vAverage.push_back(std::stod(result[9]));
                raw.vMode.push_back(std::stod(result[10]));
                raw.vMax.push_back(std::stod(result[11]));
            }
		}
		++lineIdx;
	}
}

void CrosstalkMap::getFourCorners()
{
	for (size_t i = 0; i < raw.vValid.size(); ++i)
	{
		if (raw.vValid[i] == 0)
		{
			invalidx.push_back(raw.vX[i]);
			invalidy.push_back(raw.vX[i]);
		}
	}
}

void CrosstalkMap::trimData()
{
	int iLeft = 512;
	int iRight = 1;
	int iBottom = 512;
	int iTop = 1;

	for (const auto& x : invalidx)
	{
		if (x < iLeft)  { iLeft = x; }
		if (x > iRight) { iRight = x; }
	}
	for (const auto& y : invalidy)
	{
		if (y < iBottom) { iBottom = y; }
		if (y > iTop)    { iTop = y; }
	}

#ifdef _DEBUG
	std::cout << "left: " << iLeft << std::endl;
	std::cout << "right: " << iRight << std::endl;
	std::cout << "top: " << iTop << std::endl;
	std::cout <<"bottom: " << iBottom << std::endl;
#endif // _DEBUG

	for (size_t i = 0; i < raw.vX.size(); ++i)
	{
		if ((iLeft <= raw.vX[i]) && (raw.vX[i] <= iRight)
		   && (iBottom <= raw.vY[i]) && (raw.vY[i] <= iTop))
		{
			trimmed.vX.push_back(raw.vX[i]);
			trimmed.vY.push_back(raw.vY[i]);
			trimmed.vValid.push_back(raw.vValid[i]);
			trimmed.vX0.push_back(raw.vX0[i]);
			trimmed.vY0.push_back(raw.vY0[i]);
			trimmed.va.push_back(raw.va[i]);
			trimmed.vb.push_back(raw.vb[i]);
			trimmed.vTh.push_back(raw.vTh[i]);
			trimmed.vNumOfPixel.push_back(raw.vNumOfPixel[i]);
			trimmed.vAverage.push_back(raw.vAverage[i]);
			trimmed.vMode.push_back(raw.vMode[i]);
			trimmed.vMax.push_back(raw.vMax[i]);
		}
	}
}


void CrosstalkMap::shift()
{
	double center_of_mass_x = 0;
	double center_of_mass_y = 0;

	for (size_t i =0; i < trimmed.vX0.size(); ++i)
	{
		center_of_mass_x += trimmed.vX0[i];
		center_of_mass_y += trimmed.vY0[i];
	}

	center_of_mass_x /= trimmed.vX0.size();
	center_of_mass_y /= trimmed.vY0.size();

	for (size_t i =0; i < trimmed.vX0.size(); ++i)
	{
		trimmed.vX0[i]  -= center_of_mass_x;
		trimmed.vY0[i]  -= center_of_mass_y;
	}
}


void CrosstalkMap::show_raw_data() const
{
	std::cout << "Data::show_raw_data()" << std::endl;
    for (const auto& x  : raw.vX)          { std::cout << x << " ";  } std::cout << std::endl;
    for (const auto& y  : raw.vY)          { std::cout << y << " ";  } std::cout << std::endl;
    for (const auto& v  : raw.vValid)      { std::cout << v << " ";  } std::cout << std::endl;
    for (const auto& x0 : raw.vX0)         { std::cout << x0 << " "; } std::cout << std::endl;
    for (const auto& y0 : raw.vY0)         { std::cout << y0 << " "; } std::cout << std::endl;
    for (const auto& a  : raw.va)          { std::cout << a << " ";  } std::cout << std::endl;
    for (const auto& b  : raw.vb)          { std::cout << b << " ";  } std::cout << std::endl;
    for (const auto& th : raw.vTh)         { std::cout << th << " "; } std::cout << std::endl;
    for (const auto& p  : raw.vNumOfPixel) { std::cout << p << " ";  } std::cout << std::endl;
    for (const auto& A  : raw.vAverage)    { std::cout << A << " ";  } std::cout << std::endl;
    for (const auto& M  : raw.vMode)       { std::cout << M << " ";  } std::cout << std::endl;
    for (const auto& X  : raw.vMax)        { std::cout << X << " ";  } std::cout << std::endl;
}


void CrosstalkMap::show_trimmed_data() const
{
	std::cout << "Data::show_trimmed_data()" << std::endl;
    for (const auto& x  : trimmed.vX)          { std::cout << x << " ";  } std::cout << std::endl;
    for (const auto& y  : trimmed.vY)          { std::cout << y << " ";  } std::cout << std::endl;
    for (const auto& v  : trimmed.vValid)      { std::cout << v << " ";  } std::cout << std::endl;
    for (const auto& x0 : trimmed.vX0)         { std::cout << x0 << " "; } std::cout << std::endl;
    for (const auto& y0 : trimmed.vY0)         { std::cout << y0 << " "; } std::cout << std::endl;
    for (const auto& a  : trimmed.va)          { std::cout << a << " ";  } std::cout << std::endl;
    for (const auto& b  : trimmed.vb)          { std::cout << b << " ";  } std::cout << std::endl;
    for (const auto& th : trimmed.vTh)         { std::cout << th << " "; } std::cout << std::endl;
    for (const auto& p  : trimmed.vNumOfPixel) { std::cout << p << " ";  } std::cout << std::endl;
    for (const auto& A  : trimmed.vAverage)    { std::cout << A << " ";  } std::cout << std::endl;
    for (const auto& M  : trimmed.vMode)       { std::cout << M << " ";  } std::cout << std::endl;
    for (const auto& X  : trimmed.vMax)        { std::cout << X << " ";  } std::cout << std::endl;
}
