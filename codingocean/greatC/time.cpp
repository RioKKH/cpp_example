#include <stdio.h>
#include <time.h>

int main()
{
    // ポインタの配列として曜日を準備する
    const char* wday[] = {"日", "月", "火", "水", "木", "金", "土"};
    // 1970.1.1.00:00:00からの秒数が分かる
    time_t t = time(0);
    // time(&t); // アドレスを渡す方法も使える
    printf("%ld\n", t);

    // tm構造体のアドレスを返してくる
    struct tm* p = localtime(&t);
    printf("%d年", p->tm_year + 1900); // 1900年からの年数
    printf("%d月", p->tm_mon + 1); // 0から始まるので+1。添え字になっている
    printf("%d日", p->tm_mday);
    printf("(%s)", wday[p->tm_wday]);

    printf("%02d時", p->tm_hour);
    printf("%02d分", p->tm_min);
    printf("%02d秒", p->tm_sec);

    return 0;
}

