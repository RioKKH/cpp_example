#include <endian.h>
#include <iostream>

int sum_all(int* first, int* last, int val)
{
    while (first != last)
    {
        val += *first; // firstが指す要素にアクセス
        ++first;       // 次の要素へ
    }

    return val;
}

int main()
{
    int array[10];
    // 配列の初期化
    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
    }

    int* first = &array[0];  // 先頭要素を指す
    int* last  = &array[10]; // 末尾要素の次を指す
    // 半開区間 [first, end)
    // C++のデータ構造とアルゴリズムでは半開区間が基本
    std::cout << sum_all(first, last, 0) << std::endl;
}

