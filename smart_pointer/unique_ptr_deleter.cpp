#include <iostream>
#include <memory>

#include "memory_from_storage.hpp"

// deleterとはこのようなメモリ開放時の処理を指定する、関数オブジェクトのこと
class deleter_for_storage
{
public:
    void operator()(int *ptr)
    {
        free_int_from_storage(ptr);
    }
};

int main()
{
    // テンプレート第2引数でdeleterを指定する
    std::unique_ptr<int, deleter_for_storage> ptr(malloc_int_from_storage());
    // deleterではなく、free_int_from_storageがメモリ解放の際に呼ばれる
    return 0;
}
