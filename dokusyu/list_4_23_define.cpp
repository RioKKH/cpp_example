#include <iostream>

void hello()
{
	std::cout << "hello, world" << std::endl;
}

void goodbye()
{
	std::cout << "goodbye, world" << std::endl;
}

int main()
{
	hello();

	std::cout << "hello, macro" << std::endl;
	// マクロによる識別子の置き換え処理
#define hello goodbye // helloをgoodbyeに置き換えるマクロ
	//マクロがhelloをgoodbyeに置き換える --> goodbye()が実行されgoodbyeが表示される
	hello();

	// 文字列の中に現れるのは識別子ではないので、マクロで置き換わらない。
	std::cout << "hello, macro" << std::endl;

	return 0;
}
