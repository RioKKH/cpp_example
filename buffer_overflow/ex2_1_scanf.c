#include <stdio.h>

int main() {
    char username[10];
    int is_admin = 0;

    printf("現在の管理者フラグ: %d\n", is_admin);
    printf("ユーザー名を入力してください(9文字以内) : ");

    // 危険! バッファサイズをチェックしていない
    scanf("%s", username);

    printf("入力されたユーザー名: %s=n", username);
    printf("管理者フラグの値: %d\n", is_admin);

    // 入力名が11文字以上である場合には、OSのセキュリティ機能によって
    // コアダンプが発生する為、以下のコードが実行されることはない。
    // stack smashing detected が表示される。
    // このような機能の事を Stack Canaries (スタックカナリア) と呼ぶ
    if (is_admin != 0) {
        printf("警告: 管理者ブラフが変更されました!\n");
        printf("不正アクセスの可能背があります!\n");
    }

    return 0;
}
