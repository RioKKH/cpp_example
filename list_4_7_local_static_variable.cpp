#include <iostream>

int counter()
{
	// ローカル変数をstatic変数にすると、スコープから抜けても
	// 変数が破棄されず、プログラムが終了するまで残る
	// 寿命が長くなるだけで、あくまでローカル変数。そのローカル
	// 変数が有効なスコープでしか使うことができない
	static int counter = 0;
	return ++counter;
}

int main()
{
	std::cout << "1回目: " << count() << std::endl;
	std::cout << "2回目: " << count() << std::endl;
	std::cout << "3回目: " << count() << std::endl;
}



