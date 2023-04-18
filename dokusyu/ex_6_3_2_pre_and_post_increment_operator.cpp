#include <iostream>

class A
{
public:
	A& operator++();       // 前置
	A operator++(int);     // 後置
};

A& A::operator++()
{
	std::cout << "前置インクリメント演算子" << std::endl;
	return *this;
}


A A::operator++(int)
{
	auto tmp = *this;
	std::cout << "後置インクリメント演算子" << std::endl;
	return tmp;
}

int main()
{
	A a;
	++a;
	a++;
}
