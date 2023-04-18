#include <iostream>

// 非型テンプレートパラメータを型推論する
// c++17以降で有効
template <auto i>
void show_nttp()
{
    std::cout << "show_nttp<" << i << ">()" << std::endl;
}

int main()
{
    show_nttp<0>();
    show_nttp<42>();
}
