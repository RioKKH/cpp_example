#include <iostream>

int main()
{
    auto print = [](auto s){ std::cout << s << std::endl; };

    // sizeofはバイト数を返す
    int a[5];
    print(sizeof(a));
    print(sizeof(int)); // 自分のパソコンでは4バイト
    print(sizeof(int) * 5);

    // sizeofはバイト数を返す
    double b[5];
    print(sizeof(b));
    print(sizeof(int)); // 自分のパソコンでは8バイト
    print(sizeof(double));
    print(sizeof(double) * 5);

    return 0;
}
