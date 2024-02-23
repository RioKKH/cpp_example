#include <stdio.h>
#include <time.h> // time()
#include <stdlib.h> // rand()

int main()
{

    // 乱数の種を設定する
    // strandのsはSeedの意味
    srand(time(0));

    // おみくじを引く
    const char* fortune[] = {"大吉", "中吉", "小吉", "末吉"};
    // const char* fortune[] = {"大吉", "中吉", "小吉", "末吉", "凶", "大凶"};
    int i = rand() % 4;
    printf("%s", fortune[i]);

    /*
    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }
    // 0 ~ 9までの乱数を生成
    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand() % 10);
    }
    */
    return 0;
}
