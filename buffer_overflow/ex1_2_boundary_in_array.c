#include <stdio.h>

int main() {
    char buffer[5] = {'A', 'B', 'C', 'D', 'E'};
    int important_data = 12345;

    printf("重要なデータ: %d\n", important_data);
    printf("配列の内容:");
    for (int i = 0; i < 5; i++) {
        printf("%c ", buffer[i]);
    }
    printf("\n");

    // 正常な範囲内での操作
    buffer[0] = 'X';
    printf("変更後の重要なデータ: %d\n", important_data);

    return 0;
}
