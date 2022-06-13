#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> ptr1(new int(10));

    // コピーコンストラクタやコピー代入演算子はエラー
    // std::unique_ptr<int> ptr2(ptr1); // エラー
    std::unique_ptr<int> ptr3;
    // ptr3 = ptr1;
    
    // ムーブコンストラクタやムーブ代入演算子はOK
    // この時、所有権が移動する
    std::unique_ptr<int> ptr4(std::move(ptr1)); // OK ptr1の所有権がptr4に移動する
    std::unique_ptr<int> ptr5;
    ptr5 = std::move(ptr4); // OK ptr4の所有権がptr5に移動す
}

