#include <iostream>
#include <memory>

class A
{
private:
    std::unique_ptr<int> ptr;
    // あるメモリの所有権を持つunique_ptr<T>はただ1つのみ
    // コピーが出来ない。ムーブによって所有権を移すことが出来る(c++11より)
    // 通常のポインタに匹敵する処理速度
    // 配列を扱うことが出来る
    // deleterを指定することができる

public:
    A(int val) : ptr(new int(val))
    {
    }

    int getValue() const
    {
        return *ptr;
    }
};

int main()
{
    // Aのコンストラクタでint型を動的に確保し、unique_ptrに委ねる
    A a1(10);

    // unique_ptrはコピーできないので、
    // コピーコンストラクタ−で作成しようとするとコンパイルエラー
    // A a2(a1); // error

    // 明示的にmoveするならOK
    A a2(std::move(a1));

    return 0;
} // auto_ptr同様、デストラクタで自動的にメモリ解放

