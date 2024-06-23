#include <iostream>


// auto a = [](bool b) // error
auto a = [](bool b) -> int
{
    if (b) {
        return 0;
    } else {
        return 0.0;
        // 0.0となっているが、-> intで戻り値の型を明示しているため
        // 実際には0となる
    }
};


// int
auto f()
{
    return 0;
}

// 戻り値の型の明示的な指定
auto g() -> int
{
    return 0.0;
}


int main()
{
    bool b = 0;
    std::cout << a(b) << std::endl;
    std::cout << f() << std::endl;
    std::cout << g() << std::endl;
}
