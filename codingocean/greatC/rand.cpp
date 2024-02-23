#include <stdio.h>
#include <time.h> // time()
#include <stdlib.h> // rand()

int main()
{
    // 乱数の種を設定する
    // strandのsはSeedの意味
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }
    // 0 ~ 9までの乱数を生成
    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand() % 10);
    }
    return 0;
}
