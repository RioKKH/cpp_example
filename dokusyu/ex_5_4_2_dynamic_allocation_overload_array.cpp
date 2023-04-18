#include <iostream>

class A
{
private:

public:
	A();
	explicit A(int value);
	explicit A(int value1, int value2);
	~A();

	void show_value() const;
};

A::A()
{
	std::cout << "A::A()" << std::endl;
}

A::A(int value)
{
	std::cout << value << std::endl;
}

A::A(int value1, int value2)
{
	std::cout << value1 << " " << value2 << std::endl;
}

A::~A()
{
	std::cout << "destructor" << std::endl;
}


int main()
{
	A* ptr1 = new A[3] {} ;
	delete [] ptr1;

	A* ptr2 = new A[3]
	{
		A{1}, 
		A{2},
		A{3}
	};
	delete [] ptr2;

	A* ptr3 = new A[3]
	{
		A{1, 2},
		A{3, 4},
		A{5, 6}
	};
	delete [] ptr3;

	A* ptr4 = new A[3]
	{
		A{},
		A{1},
		A{1, 2}
	};
	delete [] ptr4;

	return 0;
}



