#include <iostream>

namespace //無名名前空間
{
	void say_hello()
	{
		std::cout << "Hello, anonymous namespace" << std::endl;
	}
}

namespace // 無名名前空間
{
	namespace inner_namespace // 無名名前空間の中の名前空間
	{
		void featurex()
		{
			std::cout << "featurex()" << std::endl;
		}
	}
}

namespace outer_namespace
{
	namespace // 名前空間の中の無名名前空間
	{
		void featurey()
		{
			std::cout << "featurey()" << std::endl;
		}
	}
}


void caller()
{
	inner_namespace::featurex(); // 外側の無名名前空間の指定は無い
	outer_namespace::featurey(); // 内側の無名名前空間の指定は無い
}

int main()
{
	say_hello(); // 無名名前空間は名前空間の指定が無い
	caller();
}
