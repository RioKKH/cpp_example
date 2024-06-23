// unary operator : 単項演算子
#include <iostream>

struct IntLike{ int data; };

IntLike operator +(IntLike const & obj)
{
    return obj;
}

IntLike operator -(IntLike const & obj)
{
    // dataにマイナスをかけたIntLike型を返す必要があるので、新しくIntLike型変数を作る
    return IntLike{ -obj.data };
}
