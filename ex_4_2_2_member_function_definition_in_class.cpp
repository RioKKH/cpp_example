#include <iostream>

class A
{
private:
	int m_v;

public:
	explicit A(int v) : m_v(v)
	{
	}

	int v() const
	{
		return m_v;
	}
}


