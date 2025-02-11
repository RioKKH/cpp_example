#include <iostream>

struct null_array
{
    int dummy;
    // 引数は無視
    // []はoperator []というれっきとした演算子。
    // 演算子のオーバーロードも出来る。例えば下のように
    // 引数を無視して常に0を返すという機能を実装する。
    int &operator [](std::size_t)
    {
        dummy = 0;
        return dummy;
    }
};

int main()
{
    null_array a;

    // 0
    std::cout << a[0] << std::endl;

    // 0
    std::cout << a[999] << std::endl;

    a[100] = 0;
    // 0
    std::cout << a[100] << std::endl;
}
