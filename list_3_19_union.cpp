#include <iostream>

union U
{
	// default --> public
	float f;

private:
	int i;

public:
	U(); // constructor

	int get_i() const;
};

// コンストラクターでは先頭以外のメンバー変数で初期化できる --> 意味がわからない.
U::U() : i(0xdeadbeef)
{
	std::cout << "&f: " << &f << std::endl
	          << "&i: " << &i << std::endl;
}

int U::get_i() const
{
	return this->i; // 共用体のメンバー関数もthisが使える
}

int main()
{
	U u;
	std::cout << std::hex << u.get_i() << std::endl;
	u.f = 2.71828f;
	std::cout << std::hex << u.get_i() << std::endl;
}
