#include <iostream>
#include "test.hpp"

A::A(int a, int b) : m_a(a), m_b(b)
{
}

A::A() : A(0, 0)
{
}

A::~A()
{
}

// コピーコンストラクター
// A::A(const A& other)
A::A(const A& other) noexcept : m_a(other.m_a), m_b(other.m_b)
// A::A(const A& other) noexcept
{
	std::cout << "copy" << std::endl;
}

void A::load()
{
	m_a = 1;
	m_b = 2;
}

void A::show() const
{
	std::cout << m_a << std::endl;
	std::cout << m_b << std::endl;
}

/*
A A::operator + (const A& rhs)
{
	std::cout << "const +" << std::endl;
	this->m_a += rhs.m_a;
	this->m_b += rhs.m_b;
	return *this;
}

A A::operator - (const A& rhs)
{
	this->m_a -= rhs.m_a;
	this->m_b -= rhs.m_b;
	return *this;
}
*/

A operator + (const A& lhs, const A& rhs)
{
	std::cout << "lhs + rhs" << std::endl;
	A result{0, 0};
	result.m_a = lhs.m_a + rhs.m_a;
	result.m_b = lhs.m_b + rhs.m_b;
	return result;
}

A operator - (const A& lhs, const A& rhs)
{
	std::cout << "lhs - rhs" << std::endl;
	A result{0, 0};
	result.m_a = lhs.m_a - rhs.m_a;
	result.m_b = lhs.m_b - rhs.m_b;
	return result;
}



/*
A A::operator + (const A& rhs) const
{
	std::cout << "const const +" << std::endl;
	A temp(*this);
	temp.m_a += rhs.m_a;
	temp.m_b += rhs.m_b;
	return temp;
}

A A::operator - (const A& rhs) const
{
	A temp(*this);
	temp.m_a -= rhs.m_a;
	temp.m_b -= rhs.m_b;
	return temp;
}
*/

