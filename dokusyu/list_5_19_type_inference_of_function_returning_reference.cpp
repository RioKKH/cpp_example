#include <iostream>

// 受け取った参照をそのまま返す関数
int& id(int& i)
{
	return i;
}

int main()
{
	int i = 42;

	auto j = id(i); // jは参照？それとも値？
	
	j = 0; //参照であればiが変わっているはず

	std::cout << i << std::endl;
	// 42 -> autoは参照ではなく値になるように型推論している
	
	return 0;
}
