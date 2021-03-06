#include <iostream>

void hello()
{
	std::cout << "hello, macro" << std::endl;
}

void goodbye()
{
	std::cout << "goodbye, macro" << std::endl;
}

int main()
{
#define hello goodbye // helloをgoodbyeに置き換えるマクロ

	hello(); // マクロによりgoodbye()に置き換えられる

#undef hello // helloのマクロ定義を消す
	
	hello(); // helloのマクロの定義がなくなったので置き換えは怒らずhello()が呼ばれる

	return 0;
}
