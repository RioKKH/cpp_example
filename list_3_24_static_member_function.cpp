#include <iostream>

class S
{
	static int count; // インスタンスの数を数えるstaticメンバー変数

public:
	S();
	~S();

	static void show_count(); // static メンバー関数の宣言
};

int S::count = 0; // static メンバー変数の実体を定義して0で初期化する

S::S()
{
	// インスタンスがつくられたらインクリメントする
	++count;
}

S::~S()
{
	// 破棄されたらデクリメントする
	++count;
}

void S::show_count()
{
	std::cout << "S::count: " << count << std::endl;
}

int main()
{
	// static member functionはどのインスタンスとも結びつかずに実行可能である
	// どのインスタンスにも結びつかないのでインスタンスがなくても呼ぶことができる
	S::show_count();
	S a;
	a.show_count(); // インスタンスを使って呼び出すこともできる
	return 0;
}
