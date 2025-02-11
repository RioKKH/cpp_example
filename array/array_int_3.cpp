#include <iostream>
#include <cstdlib>

struct array_int_3
{
    int m0;
    int m1;
    int m2;

    // operator []の実装
    // m0, m1, m2への参照を返す。
    // m0, m1, m2そのものを返さないのは無駄なコピーが発生するためか？
    int &operator [](std::size_t i)
    {
        switch(i)
        {
            // []の引数が0だった場合にはm0を返す
            case 0:
                return m0;
            case 1:
                return m1;
            case 2:
                return m2;
            default:
                // 間違った引数
                // 矯正終了
                std::abort();
        }
    }
};


int main()
{
    array_int_3 a{1, 2, 3};
    std::cout << "m0: " << a.m0 << std::endl;
    std::cout << "m1: " << a.m1 << std::endl;
    std::cout << "m2: " << a.m2 << std::endl;
}
