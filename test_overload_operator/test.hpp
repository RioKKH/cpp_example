#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

class A
{
private:
	int m_a;
	int m_b;

public:
	explicit A(int a, int b);
	A();
	// コピーコンストラクタ
    // A(const A& other);
	A(const A& other) noexcept;
	~A();


	void load();
	void show() const;

	// A operator + (const A& rhs);
	// A operator - (const A& rhs);

	friend A operator + (const A& lhs, const A& rhs);
	friend A operator - (const A& lhs, const A& rhs);
	
	// A operator + (const A& rhs) const;
	// A operator - (const A& rhs) const;
};

#endif // TEST_HPP
