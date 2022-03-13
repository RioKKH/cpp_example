#include <iostream>

// 関数ポインターや関数リファレンスを引数に持っていたり、
// 戻り値として返す関数を高階関数 higher order function
// という。高階関数は関数の動作をカスタマイズするために
// 使われる

// predicateがtrueを返した要素のみをコンソールに出力する関数
void filtered_show(int (&array)[5], bool (*predicate)(int))
{
	for (int e : array)
	{
		if (predicate(e))
		{
			std::cout << e << std::endl;
		}
	}
}

// 奇数ならtrueを返す関数
bool is_odd(int v)
{
	return (v % 2) == 1;
}

// 5より小さいならtrueを返す関数
bool is_less_than_5(int v)
{
	return v < 5;
}

int main()
{
	int array[] = {5, 10, 3, 0, 1};
	filtered_show(array, &is_odd); // higer order function!!

	std::cout << std::endl;

	filtered_show(array, &is_less_than_5); // higher order function!!
}

