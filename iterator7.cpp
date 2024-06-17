#include <iostream>

struct IntLike
{
    int data {};

    // 前置 演算子のオーバーロードの宣言
    IntLike &operator ++()
    {
        ++data; // データメンバをインクリメント
        return *this;
    }

    // 後置 演算子のオーバーロードの宣言
    // 前置と後置は区別出来る必要がある。
    // C++は区別の方法として、int型の仮引数を1つ取るoperator ++を後置演算子と
    // 認識する文法を採用した。
    IntLike operator ++(int)
    {
        IntLike copy = *this;
        // 後置インクリメント演算子が呼ばれたオブジェクトに対して
        // 前置インクリメント演算子を使用している。
        ++*this; // ++dataとしても良い
        return copy;
    }
};

int main()
{
    IntLike i{0};

    // 前置
    std::cout << (++i).data << std::endl; // 1

    // 後置
    std::cout << (i++).data << std::endl; // 1
    std::cout << i.data << std::endl;   // 2
}

