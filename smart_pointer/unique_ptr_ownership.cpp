#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> ptr1;
    // メモリの所有権を保持しているかどうかは、boolの文脈で使用
    // することで判定出来る。所有していればtrueを返す.
    if (ptr1)
    {
        std::cout << "Has ownership." << std::endl;
    }
    else
    {
        std::cout << "Does not have ownership." << std::endl;
    }

    std::unique_ptr<int> ptr2(new int (10));
    if (ptr2)
    {
        std::cout << "Has ownership." << std::endl;
    }
    else
    {
        std::cout << "Does not have ownership." << std::endl;
    }

    return 0;
}

