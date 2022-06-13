#include <iostream>
#include <memory>

int main()
{
    // コンストラクタの引数として動的確保下メモリのアドレスを指定
    std::unique_ptr<int> ptr(new int(10));
    std::cout << *ptr << std::endl;

    // reset関数を使ってあとから代入することも出来る
    std::unique_ptr<int> ptr2;
    ptr2.reset(new int(20));
    std::cout << *ptr2 << std::endl;

    // c++14以降であれば、make_unique関数を使うことも出来る
    std::unique_ptr<int> ptr3 = std::make_unique<int>(30);
    std::cout << *ptr3 << std::endl;

    return 0;
}
