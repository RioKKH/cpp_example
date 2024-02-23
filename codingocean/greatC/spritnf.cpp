#include <stdio.h>
// #include <process.h>

int main()
{
    char name[128] = "AKB";
    int num = 48;

    char str[128];
    // sprintfのsはstringのs
    // メモリ上に文字列を作成する
    // 文字列と数値を結合する事ができる
    // printf("%s%d", name, num);
    sprintf(str, "%s%d", name, num);
    printf("%s\n", str);

    sprintf(str, "%s%f", "PI=", 3.14159f);
    printf("%s\n", str);

    return 0;
}
