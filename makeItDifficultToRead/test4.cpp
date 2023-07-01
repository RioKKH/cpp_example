#include <iostream>
#include <functional>
#include <map>


// 実行する関数オブジェクト1	
class my_func1
{
public:
	void operator()(int x) const
	{
		std::cout << x << std::endl;
	}
};

// 実行する関数オブジェクト2
class my_func2
{
public:
	void operator()(int x) const
	{
		std::cout << x << x << std::endl;
	}
};

auto my_func3 = [](std::string line)
{
	std::cout << line << std::endl;
};


std::map<int, std::function<int(int)>> m
{
	{0, [](int x) { return x * 2; }},
	{1, [](int x) { return x * 3; }},
	{2, [](int x) { return x * 4; }},
};



class A
{
private:

public:
	explicit A()
	{
	}

	~A()
	{
	}

	std::string converter(int i, std::string line)
	{
		return m2[i](line);
	};

	std::map<int, std::function<std::string(std::string)>> m2
	{
		{0, [](std::string line)
			{ return line; }
		},
		{1, [](std::string line)
			{ return "1" + line; }
		},
	};
};



int main()
{
	A a = A();

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << a.converter(i, "hello") << std::endl;
		}
	}

	return 0;
}


