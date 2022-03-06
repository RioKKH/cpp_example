#include <iostream>

extern "C" // Cリンケージを一括でしていして、C言語から呼べるようにした
{
	void call_c();
	void call_cpp()
	{
		std::cout << "call_cpp" << std::endl;
		call_c();
	}
}
