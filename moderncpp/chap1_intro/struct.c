#include <stdio.h>
#include <stdlib.h>

// 構造体を定義する
typedef struct _MyStructure {
    int id;
    char name[16];
} MyStructure;

int main() {
    // 構造体のメモリを確保する。
    MyStructure *s = (MyStructure *)malloc(sizeof(MyStructure));

    // 構造体のメンバを初期化する
    s->id = 1;
    s->name[0] = 'A';

    // 構造体のメンバを表示する
    printf("%d: %c\n", s->id, s->name[0]);
    
   // 構造体のメモリを解放する
    free(s);

    return 0;
}
