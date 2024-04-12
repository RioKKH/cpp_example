#include <iostream>
#include <memory>

using namespace std;

int main() {
    // 所有権を共有できるスマートポインタ (C++11)
    // shared_ptrはコピーコンストラクタとコピー代入演算子を持っているので
    // 代入によって所有権のコピーが実行され、s_str_ptrとs_str_ptr2が同じ
    // メモリ領域を所有するものとしてマークされる
    auto s_str_ptr = make_shared<string>("Hello, World!");
    auto s_str_ptr2 = s_str_ptr;

    // 共有メモリなので片方を変更するともう片方も変更される
    cout << *s_str_ptr << endl << *s_str_ptr2 << endl; // 問題なく2つ表示される

    *s_str_ptr = "Hello, C++ World!";

    cout << *s_str_ptr << endl << *s_str_ptr2 << endl; // 双方ともに書き換わる

    auto s_str_ptr3 = std::move(s_str_ptr);
    // s_str_ptrをmove後もs_str_ptr2の所有権は生きている事に注意
    std::cout << *s_str_ptr2 << std::endl << *s_str_ptr3 << std::endl;
    std::cout << *s_str_ptr  << std::endl; // segmentation fault
    return 0;
}
