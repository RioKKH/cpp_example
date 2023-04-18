#include <iostream>
#include <vector>

int main()
{
	std::vector<int> empty; // からの動的配列
	std::cout << "empty.size() : " << empty.size() << std::endl;

	std::vector<int> array = {10, 20, 30, 40, 50}; // {}を使って初期化
	std::cout << "array.size(): " << array.size() << std::endl;

	// 範囲for文でも走査できる
	for (int e : array)
	{
		std::cout << e << std::endl;
	}

	return 0;
}
