#include <stdio.h>

int main() {
    char buffer[8];
    int secret_code = 9999;
    int user_level = 1;

    printf("=== 初期状態 ===\n");
    printf("buffer のアドレス: %p\n", buffer);
    printf("secret_code のアドレス: %p, 値: %d\n", &secret_code, secret_code);
    printf("user_level のアドレス: %p, 値: %d\n", &user_level, user_level);

    printf("\n文字列を入力してください: ");
    scanf("%s", buffer);

    printf("\n=== 入力後の状態 ===\n");
    printf("buffer: %s\n", buffer);
    printf("secret_code: %d\n", secret_code);
    printf("user_level: %d\n", user_level);

    // メモリダンプ表示（上級者向け）
    printf("\n=== メモリダンプ ===\n");
    unsigned char* ptr = (unsigned char*)buffer;
    for (int i = -8; i < 16; i++) {
        printf("アドレス %p: 0x%02x (%c)\n", ptr + i, *(ptr + i),
               (*(ptr + i) >= 32 && *(ptr + i) <= 126) ? *(ptr + i) : '.');
    }

    return 0;
}
