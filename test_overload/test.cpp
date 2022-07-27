#include <iostream>
#include "test.hpp"

A::A()
{
}

A::~A()
{
}

void A::set()
{
	set(0);
}

void A::set(int a)
{
	this->a = a;
}

void A::show() const
{
	std::cout << this->a << std::endl;
}

