#include <stdio.h>

// メモリアライメント確認用の構造体
struct test {
    int a;
    char name[10];
};

int check_memory_alignment() {
    printf("データ型のサイズ確認\n");
    printf("sizeof(int): %zu バイト\n", sizeof(int));
    printf("sizeof(char): %zu バイト\n", sizeof(char));
    printf("sizeof(char[10]): %zu バイト\n", sizeof(char[10]));
    printf("struct testのサイズ: %zu バイト\n", sizeof(struct test));

    return 0;
}

int main() {
    int a = 100;
    int b = 200;
    char name[10] = "Alice";

    printf("変数aのアドレス: %p, 値: %d\n", &a, a);
    printf("変数bのアドレス: %p, 値: %d\n", &b, b);
    printf("配列nameのアドレス: %p, 値: %s\n", name, name);

    if (check_memory_alignment() != 0) {
        printf("__FILE__, __LINE__, check_memory_alignmentがこけました。\n");
        return 1;
    }

    /* 実行結果例
     * 変数aのアドレス: 0x7ffe32b653a4, 値: 100
     * 変数bのアドレス: 0x7ffe32b653a8, 値: 200 (差: +4バイト)
     * 配列nameのアドレス: 0x7ffe32b653ae, 値: Alice (差: +6バイト)
     *
     * メモリ配置は以下の様になっていると考えられる
     * 高位アドレス
     * ↓
     * [  name[9]  ] 0x7ffe32b653b7
     * [  name[8]  ] 0x7ffe32b653b6
     * [   ...     ]
     * [  name[1]  ] 0x7ffe32b653af
     * [  name[0]  ] 0x7ffe32b653ae ← nameの開始アドレス
     * [  padding  ] 0x7ffe32b653ad (アライメント用)
     * [  padding  ] 0x7ffe32b653ac
     * [    b[3]   ] 0x7ffe32b653ab
     * [    b[2]   ] 0x7ffe32b653aa
     * [    b[1]   ] 0x7ffe32b653a9
     * [    b[0]   ] 0x7ffe32b653a8 ← bの開始アドレス
     * [    a[3]   ] 0x7ffe32b653a7
     * [    a[2]   ] 0x7ffe32b653a6
     * [    a[1]   ] 0x7ffe32b653a5
     * [    a[0]   ] 0x7ffe32b653a4 ← aの開始アドレス
     * ↓
     * 低位アドレス
     */

    return 0;
}
