#include <iostream>

class Vector3d
{
private:
	float x{1};
	float y{2};
	float z{3};

public:
	Vector3d();
	void show() const;
};

Vector3d::Vector3d()
	: x(0), y(0), z(0)
{
}

void Vector3d::show() const
{
	std::cout << x << " " << y << " " << z << std::endl;
}

int main()
{
	Vector3d v; // NSDMI
	v.show();
	return 0;
}




