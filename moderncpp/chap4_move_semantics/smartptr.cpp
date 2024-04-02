#include <iostream>
#include <memory>     // スマートポインタの利用に必要
#include <tuple>      // タプルの利用に必要

int main() {
    {
        auto u_str_ptr = std::make_unique<std::string>("Hello, World!");
        std::cout << *u_str_ptr << std::endl;
        // ブロック出口で所有権を失う。メモリ領域も解放される
    }
    {
        auto u_str_ptr = std::make_unique<std::string>("Hello, World!");
        // auto u_str_ptr2 = ustr_ptr; // 代入はコンパイルエラー
        auto u_str_ptr2 = std::move(u_str_ptr);
        std::cout << *u_str_ptr2 << std::endl;
        // std::cout << *ustr_ptr << std::endl; // segmentation fault
    }

    return 0;
}



