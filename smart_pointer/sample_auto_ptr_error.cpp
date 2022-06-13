#include <iostream>
#include <memory>

class A
{
private:
    std::auto_ptr<int> ptr;

public:
    A(int val_) : ptr(new int(val_))
    {
    }

    int getValue() const
    {
        return *ptr;
    }
};

int main()
{
    // Aのコンストラクタでint型を動的に確保し、auto_ptrに委ねる
    A a1(10);

    // コピーコンストラクタで2つ目のAを作成
    // この時、a.ptrからa.ptr2に所有権が移動
    A a2(a1);

    // a1の値を呼び出す
    a1.getValue(); // error

    // 実行時エラー！
    // a1.ptrはすでに所有権をうしなっているのでアクセスできない
    
    return 0;
}

