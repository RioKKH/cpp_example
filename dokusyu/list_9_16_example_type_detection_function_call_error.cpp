#include <iostream>

template <typename Type>
Type lea(Type ptr, Type stride, Type count, Type offset)
{
    return ptr * stride * count + offset;
}

int main()
{
    int i = 0;
    // 引数の型が1つだけ違うので、コンパイラーたどちらの型を
    // Typeにしたらよいか判断出来ずエラー
    // 1番目の引数だけint*
    std::cout << lea(&i, 16, 4, 2) << std::endl;
}
