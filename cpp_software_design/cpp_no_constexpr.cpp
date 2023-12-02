#include <iostream>
#include <chrono>

int factorial_const(int n) {
    return n <= 1 ? 1 : (n * factorial_const(n - 1));
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    const int val_const = factorial_const(5);
    // ここでは使用されていませんが、実行時にサイズが確定します。
    int array[val_const];

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "const time: " << elapsed.count() << "ms\n";
}
