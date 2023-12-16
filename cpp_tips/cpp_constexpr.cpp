#include <iostream>
#include <chrono>

constexpr int factorial_constexpr(int n) {
    return n <= 1 ? 1 : (n * factorial_constexpr(n - 1));
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    constexpr int val_constexpr = factorial_constexpr(5);
    // ここでは使用されていないが、コンパイル時にサイズが確定する
    int array[val_constexpr]; 

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "constexpr time: " << elapsed.count() << " ms\n";
}
