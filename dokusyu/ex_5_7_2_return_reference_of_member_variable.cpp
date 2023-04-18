#include <iostream>

class A
{
private:
	int m_i;

public:
	A(int m_i) : m_i(m_i)
	{
	};

	int& show()
	{
		std::cout << m_i << std::endl;
		return m_i;
	};

	const int& show() const
	{
		std::cout <<  m_i << std::endl;;
		return m_i;
	};
};

int main()
{
	A a{0};
	a.show();
	
	return 0;
}
