#include <iostream>

int main()
{
	int i = 42;

	{
		int i = 72; // 異なるスコープでは同じ名前のローカル変数おｗ作ることができる

		// 現在のスコープから順番に遡って最も内側にあるへんすうが使われる
		std::cout << "inner: " << &i << ": " << i << std::endl;

		i = 0; // 内側の変数に代入される
	}

	// 内側のスコープの変数は無効となっているので、外側の変数が使われる。
	std::cout << "outer: " << &i << ": " << i << std::endl;

	return 0;
}
