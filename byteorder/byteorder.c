#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

void print_bytes(uint32_t value) {
    unsigned char *ptr = (unsigned char *)&value;
    for (int i = 0; i < sizeof(uint32_t); i++) {
        printf("%02X ", ptr[i]);
    }
    printf("\n");
}

int main() {
    uint32_t num = 0x12345678; // テスト用の数値。32bit=4byteの整数型
                               // 0x12345678 は 305419896 という10進数
    printf("オリジナル値: ");
    print_bytes(num);

    // リトルエンディアン (多くのx86システムのネイティブオーダー)
    printf("リトルエンディアン: ");
    print_bytes(num);

    // ビッグエンディアン (ネットワークバイトオーダー)
    uint32_t big_endian = htonl(num);
    printf("ビッグエンディアン (ネットワークバイトオーダー): ");
    print_bytes(big_endian);

    return 0;
}







