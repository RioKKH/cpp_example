#include <iostream>

int main()
{
    char c = 99;
    
    // C++には5種類のキャスト演算子があるが、最も基本的なのが
    // 以下に示すstatic_cast演算子。
    // キャスト演算子を使ってint型に変換して表示する
    std::cout << static_cast<int>(c) << std::endl;
}
