#include <iostream>

struct IntLike
{
    int data;

    IntLike operator +(IntLike const &right)
    {
        return IntLike {data + right.data};
    }
};

int main()
{
    IntLike a{1};
    IntLike b{2};

    // オーバーロードされた演算子としての使い方
    IntLike c = a + b;
    // 普通のメンバー関数としての使い方
    IntLike d = a.operator +(b);

    std::cout << c.data << std::endl;
    std::cout << d.data << std::endl;
}
