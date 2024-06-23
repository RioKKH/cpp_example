#include <stdio.h>
#include <stdlib.h>    // malloc free
#include <string.h>    // memset memcpy
#include <proc_service.h>
#include <stdlib.h>
#include <type_traits> // extent
#include <assert.h>    // assert

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
    // テンプレート関数を使って配列の要素数を取得する
    size_t numElements = countof(src);
    printf("要素数:%zd\n", numElements);

    GROUP* dst = (GROUP *)malloc(sizeArray);
    // GROUP* dst = NULL; // assertでエラーを発生させるためにNULLを代入
    assert(dst != NULL);
    // 配列の初期化
    memset(dst, 0, sizeArray);
    // 配列のコピー
    memcpy(dst, src, sizeArray);

    for (size_t i = 0; i < numElements; i++) {
        printf("name:%s num:%d\n", dst[i].name, dst[i].num);
    }
    free(dst);

    return 0;
}
