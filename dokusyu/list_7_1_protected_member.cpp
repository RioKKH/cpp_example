#include <iostream>

class Base
{
// 被保護メンバー protected member
protected:
	void protected_member()
	{
		std::cout << "Base::protected_member()" << std::endl;
	}
};

class Derived : public Base
{
public:
	void member_test();
};

void Derived::member_test()
{
	// OK. 基底クラスの被保護メンバーには派生クラスからアクセス出来る
	protected_member();
}

int main()
{
	Derived derived;

	// error. publicで派生しても被保護メンバーは外部からアクセス出来ない
	// derived.protected_member();
	

	// OK. 公開メンバーには外部からもアクセス出来る
	derived.member_test();

	return 0;
}
