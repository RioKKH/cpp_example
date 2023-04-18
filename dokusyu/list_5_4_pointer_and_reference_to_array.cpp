#include <iostream>

int main()
{
	int array[5] = {0, 1, 2, 3, 4};
	
	// 括弧を忘れたり、* &の位置が異なると別の意味になるので注意
	int (*ptr)[5] = &array; // 配列へのポインター

	// 配列へのポインターや参照は型に配列の長さ情報をもっているので、
	// 範囲for文で走査することができる
	for (int e : *ptr) // ポインターなので関節参照演算子が必要
	{
		std::cout << e << std::endl;
	}

	std::cout << std::endl;

	int (&ref)[5] = array; // 配列への参照

	for (int e : ref) // 参照なので関節参照演算子は不要
	{
		std::cout << e << std::endl;
	}

	// 配列へのポインターや参照は括弧があり使いづらいので
	// 必要となった場合には型に別名を与えると良い
	using int_array = int[5];
	int_array array2; // 長さ5のint型の配列
	int_array* aptr = &array2; // 長さ5のint型の配列へのポインター
	int_array& aref = array2;  // 長さ5のint型の配列への参照


	using int_array_pointer = int (*)[5];
	int_array_pointer ptr2 = &array2; // 長さ5のint型の配列へのポインター

	using int_array_reference = int (&)[5];
	int_array_reference ref2 = array2; // 長さ5のint型の配列への参照

	return 0;
}
