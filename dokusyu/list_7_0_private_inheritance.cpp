#include <iostream>

class Base
{
private:
	void  private_member()
	{
		std::cout << "Base::private_member()" << std::endl;
	}

public:
	void public_member()
	{
		std::cout << "Base::public_member()" << std::endl;
	}
};

class Derived : private Base // 非公開で派生
{
	public:
		void member_test();
};

void Derived::member_test()
{
	private_member(); // Error. 基底クラスの非公開メンバーにはアクセス出来ない
	public_member();  // OK. 基底クラスの公開メンバーにはアクセス出来る
}

int main()
{
	Base base;
	Derived derived;

	base.private_member(); // Error.
	base.public_member();  // OK. 派生クラスがprivateで派生していたも
	                       // それは基底クラス自身に影響は与えない
	derived.private_member(); // Error.
	derived.public_member();  // Error. privateで派生しているので、
	                          // 非公開メンバーとなっている
	return 0;
}

