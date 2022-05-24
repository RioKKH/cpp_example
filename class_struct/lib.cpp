#include <iostream>
#include "lib.hpp"

classstruct::classstruct()
{
    t.a = 1.0;
    t.b = 2.0;
}

classstruct::~classstruct()
{
}

void classstruct::show(void)
{
    std::cout << t.a << std::endl;
    std::cout << t.b << std::endl;
}

int classstruct::geta(void) const
{
    return t.a;
}

int classstruct::getb(void) const
{
    return t.b;
}

test classstruct::getTest(void) const
{
    return t;
}

