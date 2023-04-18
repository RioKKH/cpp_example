#include <iostream>

class A
{
public:
	A();
	~A();
};

A::A()
{
	std::cout << "コンストラクター" << std::endl;
}

A::~A()
{
	std::cout << "デストラクター" << std::endl;
}

// メイン関数の外部でインスタンスを生成している
// インスタンスaのデストラクタが呼ばれるのはmain関数終了後となることが期待される
A a; // グローバル変数

int main()
{
	std::cout << "main()関数" << std::endl;
}

// 実際にmain()関数終了後にAのデストラクターが呼ばれていることがわかる
