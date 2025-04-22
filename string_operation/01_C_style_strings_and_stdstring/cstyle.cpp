#include <iostream>

int main()
{
    // Cスタイル文字列
    // ヌル終端('\0')によって文字列の終わりを表現
    char s1[10] = "Hello";
    char *s2 = "World"; // s2はリテラル領域。書き換え不可
    std::cout << s1 << ", " << s2 << std::endl;

    return 0;
}
