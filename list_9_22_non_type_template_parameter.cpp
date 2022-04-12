#include <iostream>

// 非型テンプレートパラメータ
// Non-Type Template Parameter : NTTP
// 型だけではなく、コンパイル時に扱える値も受け取ることが出来る
// 非型テンプレートパラメータはtypenameキーワードの代わりに受け取りたい値
// の型を書く  
template <int i>
void show_nttp()
{
    std::cout << "shot_nttp<" << i << ">()" << std::endl;
}

int main()
{
    show_nttp<0>();
    show_nttp<42>();
}
