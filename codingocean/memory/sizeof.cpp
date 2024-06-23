#include <stdio.h>
#include <proc_service.h>
#include <stdlib.h>
#include <type_traits> // extent

/**
 * T型のN要素の配列arrの定数参照
 * 配列のサイズNをテンプレート引数として受け取る
 */
template <typename T, size_t N>
size_t countof(const T (& arr)[N])
{
    // 配列のサイズをコンパイル時に取得するためのメタプログラミング手法
    // メタプログラミングとは、コードの生成や最適化がコンパイル時に
    // 行われるプログラミング手法のこと。
    // C++のテンプレートはメタプログラミングの手法の一つ
    return std::extent<T[N]>::value;
}

int main() {
    typedef struct GROUP {
        char name[4];
        int num;
    } GROUP;
    GROUP src[] = {
        "STU", 48,
        "NMB", 49,
        "AKB", 50,
    };
    size_t sizeArray = sizeof(src);
    printf("配列全体のサイズ:%zd\n", sizeArray); // 24

    size_t sizeElement = sizeof(src[0]);
    printf("1要素のサイズ:%zd\n", sizeElement);

    // 下のように書くのは面倒
    // size_t numElements = sizeof(src) / sizeof(src[0]);
    // なのでマクロが用意されている
    size_t numElements = countof(src);
    printf("要素数:%zd\n", numElements);

    return 0;
}
