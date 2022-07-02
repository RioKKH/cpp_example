#include <iostream>
#include <memory>

int main()
{
    // コンストラクタやreset関数を使ってのメモリ割当が可能
    std::shared_ptr<int> ptr(new int(10));
    std::shared_ptr<int> ptr2;
    ptr2.reset(new int(10));

    // make_shared関数を使うと、効率良くメモリを確保出来る
    std::shared_ptr<int> ptr3 = std::make_shared<int>(10);

    // 複数の引数を持つコンストラクタも、make_sharedから呼び出せる。
    typedef std::pair<int, double> int_double_t;
    std::shared_ptr<int_double_t> ptr4 = std::make_shared<int_double_t>(10, 0.4);
    std::cout << "ptr4 " << ptr4 << std::endl;
}
