#include <iostream>
#include <memory>

int main()
{
    // int型のメモリを動的に確保し、その所有権をauto_ptrに委ねる
    // auto_ptr is deprecated so don't use it.
    std::auto_ptr<int> ptr(new int(10));

    // operator*()で生ポインタのようにアクセス出来る
    for (int i = 0; i < 10; ++i)
    {
        *ptr += 1;
    }
    std::cout << "ptr = " << *ptr << std::endl;

    return 0;
}
