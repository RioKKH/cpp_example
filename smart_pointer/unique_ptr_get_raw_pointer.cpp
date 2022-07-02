#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> ptr(new int(10));

    // 通常のpointerがほしい時にはget関数を使う。
    // ポインタの所有権はunique_ptrが保持し続ける
    int *pint;
    pint = ptr.get();
    std::cout << pint << std::endl;
    std::cout << *pint << std::endl;

    // 所有権自体を放棄する場合は、release関数を使う。
    // この場合、メモリの解放自体は自分で行う必要がある。
    pint = ptr.release();
    delete pint;
    std::cout << pint << std::endl;
    std::cout << *pint << std::endl;
}
