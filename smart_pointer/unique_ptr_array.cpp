#include <iostream>
#include <vector>
#include <memory>

int main()
{
    // 型名[]をテンプレート引数に指定することで配列も扱える
    std::unique_ptr<int[]> ptrArray(new int[10]);

    // 配列型の場合、operator[](size_t)を使うことが出来る
    for (int i = 0; i < 10; ++i)
    {
        ptrArray[i] = i;
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << ptrArray[i] << " ";
    }
    std::cout << std::endl;
    return 0;
} // 配列型の場合、自動的にdelete[]がよばれて解放される 
