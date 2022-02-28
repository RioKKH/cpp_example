#include <iostream>

class vector3d
{
public:
	using element_type = int;

private:
	element_type x;
	element_type y;
	element_type z;

public:
	element_type getX();
	void setX(element_type X);

	element_type getY();
	void setY(element_type Y);

	element_type getZ();
	void setZ(element_type Z);
};

vector3d::element_type vector3d::getX()
{
	return x;
}

void vector3d::setX(element_type X)
{
	x = X;
}

vector3d::element_type vector3d::getY()
{
	return y;
}

void vector3d::setY(element_type Y)

{
	y = Y;
}

vector3d::element_type vector3d::getZ()
{
	return z;
}

void vector3d::setZ(element_type Z)
{
	z = Z;
}


vector3d set(vector3d::element_type x, vector3d::element_type y, vector3d::element_type z)
{
	vector3d vec;
	vec.setX(x);
	vec.setY(y);
	vec.setZ(z);

	return vec;
}

// overload of function
vector3d set(vector3d::element_type x, vector3d::element_type y)
{
	return set(x, y, 0);
};

// default argument
/*
vector3d set(vector3d::element_type x,
		     vector3d::element_type y,
			 vector3d::element_type z = 0)
{
	vector3d vec;
	vec.setX(x);
	vec.setY(y);
	vec.setZ(z);

	return vec;
}
*/


int main()
{
	int x = 0;
	int y = 0;
	int z = 0;

	// std::cin >> x >> y >> z;

	// vector3d vec;

	// vec.setX(x);
	// vec.setY(y);
	// vec.setZ(z);

	vector3d vec2 = set(1, 2, 3);
	std::cout << vec2.getX() << std::endl;

	return 0;
}
