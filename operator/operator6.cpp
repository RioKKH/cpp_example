#include <iostream>
// unary operatorの実装
// 単項演算子をオーバーロードする実装

struct IntLike { int data; };

// 引数を変更するので、constではないreferenceを使う
// 戻り値は引数をそのままreferenceで返す
IntLike &operator ++(IntLike &obj)
{
    ++obj.data;
    return obj;
}

IntLike &operator --(IntLike &obj)
{
    --obj.data;
    return obj;
}


