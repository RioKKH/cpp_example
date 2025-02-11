#include <iostream>

int main()
{
    try {
        throw 123; // int 型
    } catch(int e) {
        std::cout << e << std::endl;
    }

    // 実行される
    std::cout << "resumed." << std::endl;
}
