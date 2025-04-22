#include <iostream>
#include <string>
#include <cstring>

int main()
{
    // 十分なバッファを確保すること
    char a[30] = "Tokyo";
    // char *a = "Tokyo"; これだと書き換え不可能なので、strcat()出来ない
    const char *b = "2025";
    char *c = strcat(a, b);

    std::cout << c << " (length = " << std::strlen(c) << ")" << std::endl;

    std::string A = "Tokyo";
    std::string B = "2025";
    std::string C = A + B;
    std::cout << C
              << " (length = " << C.length() << ")" << std::endl;

    return 0;
}
