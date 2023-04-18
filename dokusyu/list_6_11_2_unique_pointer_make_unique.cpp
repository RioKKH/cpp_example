#include <iostream>
#include <memory>
#include <utility>
#include <array>

class A
{
private:
	int m_a;
	float m_b;

public:
	explicit A(int a, float b);
	~A();

	void set_a(int a);
	int a() const;

	void set_b(float b);
	float b() const;
};


A::A(int a, float b)
{
	std::cout << a << "," << b << std::endl;
}

A::~A()
{
	std::cout << " destructor " << std::endl;
}

void A::set_a(int a) 
{
	m_a = a;
}

int A::a() const
{
	return m_a;
}

void A::set_b(float b)
{
	m_b = b;
}

float A::b() const
{
	return m_b;
}


int main()
{
	{
		auto ptr = std::make_unique<A>(0, 1.0f);
	}

	{
		std::array<std::unique_ptr<A>, 3> ptr2;
		for (int i=0; i<3; ++i)
		{
			std::cout << i << std::endl;
			ptr2[i]->set_a(i);
		}

		for (int i=0; i<3; ++i)
		{
			std::cout << ptr2[i]->a() << std::endl;
		}
	}
}
