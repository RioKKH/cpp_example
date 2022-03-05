#include <iostream>

class A
{
public:
	~A();
};

A::~A()
{
	std::cout << "デストラクター呼び出し" << std::endl;
}

void function_scope(int i)
{
	A a; // 関数スコープから抜けるとデストラクターが呼ばれる
	std::cout << "関数スコープ" << std::endl;

	if (i > 0)
	{
		return ; // 関数の処理がここから呼び出し元に戻る
	}
	
	std::cout << "if文の後" << std::endl;
}

int main()
{
	// if 文の条件がtrueとなるのでreturnが戻ってくる
	function_scope(10);

	std::cout << std::endl;

	// if文の条件がfalseとなるので関数スコープの終わりに辿り着く
	function_scope(-10);

	return 0;
}
