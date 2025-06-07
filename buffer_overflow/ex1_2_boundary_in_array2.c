#include <stdio.h>

int main() {
    char buffer[5] = {'A', 'B', 'C', 'D', 'E'};
    int important_data = 12345;

    printf("=== 初期状態 ===\n");
    printf("重要なデータ: %d\n", important_data);
    printf("buffer アドレス: %p\n", buffer);
    printf("important_data アドレス: %p\n", &important_data);
    printf("距離: %ld バイト\n", (char*)&important_data - buffer);

    printf("\n=== 正常な操作（範囲内）===\n");
    buffer[0] = 'X';  // ✅ 安全
    buffer[4] = 'Z';  // ✅ 安全（最後の要素）
    printf("変更後の重要なデータ: %d\n", important_data);

    printf("\n=== 危険な操作（範囲外）===\n");
    printf("buffer[5]にアクセスしてみます...\n");
    buffer[5] = '!';  // ⚠️ 危険！範囲外アクセス
    printf("範囲外アクセス後の重要なデータ: %d\n", important_data);

    printf("\n=== さらに危険な操作 ===\n");
    printf("buffer[6], buffer[7], buffer[8]にアクセス...\n");
    buffer[6] = 'A';  // ⚠️ より危険
    buffer[7] = 'T';  // ⚠️ より危険
    buffer[8] = 'K';  // ⚠️ より危険
    printf("複数範囲外アクセス後の重要なデータ: %d\n", important_data);

    return 0;
}
