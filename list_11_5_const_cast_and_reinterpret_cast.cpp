#include <cstdint>      // std::intptr_tのため
#include <iostream>

/*
 * 4つのキャスト演算子
 * static_cast<target-type>(expr)
 *  コンパイル時に与えられた型情報に基づいた型変換
 * const_cast<target-type>(expr)
 *  ポインターや参照からconstを外したりつけたりする
 * reinterpret_cast<taret-type>(expr)
 *  ポインター型と整数型の直接変換。
 *  本来許されないキャストを行うために用いられるので深い理解が必要
 * dynamic_cast<target-type>(expr)
 *  C++で追加された機能に対して使われるキャスト。別途説明する
 */

// 様々な理由でconst修飾されていない安全ではない関数
// 特にC言語との兼ね合いでこのようになっている事が多い
extern "C" void unsafe_c_function(char* str)
{
    std::cout << "unsafe_c_function: " << str << std::endl;
}

// 様々な理由で正しい型を受け取れない関数
// コールバックAPIなどによくみられる
// コールバック関数とは、引数として他の関数に渡され、外側の関数の
// 中で呼び出された、何等かのルーチンやアクションを完了させる関数
void unsafe_interface_function(void *data)
{
    // std::intptr_t ポインタサイズの符号付き整数型
    // ポインター型の値をすべて表現することが出来ることが保証された特別な符号付整数型
    auto value = reinterpret_cast<std::intptr_t>(data);
    std::cout << "unsafe_interface_function: " << value << std::endl;
}

int main()
{
    const int value = 72;
    // messageにはconst が付いているが…
    const char message[] = "constant string";
    
    // 関数に渡せるようにconstを外す
    unsafe_c_function(const_cast<char*>(message));

    // 数値をポインター型に変換して渡す
    unsafe_interface_function(reinterpret_cast<void*>(static_cast<std::intptr_t>(value)));

    return 0;
}
