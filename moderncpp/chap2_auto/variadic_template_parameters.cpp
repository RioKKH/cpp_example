#include <iostream>

template <typename... Args>
void printValues(Args... args) {
    // Args: 型のパラメータパック
    // args: 値のパラメータパック
    // ...: パックが複数の要素を持つことを示す
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

template <typename... Args>
auto sum(Args... args) {
    return (... + args); // 二項のfold expression
}

int main() {
    printValues(1, 2.5, "Hello");
    // (std::cout << 1 << " "), (std::cout << 2.5 << " "),
    // (std::cout << "Hello" << " ")の様に展開される。
    // 勿論最後にはstd::cout << std::endl;が呼ばれる。
    printValues(true, 'A');
    int result = sum(1, 2, 3, 4, 5);
    // ((((1 + 2) + 3) + 4) + 5)の様に展開される。
    std::cout << result << std::endl;
    return 0;
}
