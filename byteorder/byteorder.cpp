#include <iostream>
#include <iomanip>
#include <array>
#include <cstdint>
#include <algorithm>
#include <arpa/inet.h>

class ByteOrderDemo {
private:
    // 実際にはstaticをつけなくてもconstexprを使えば、自動的に
    // staticな変数になる。
    static constexpr size_t UINT32_SIZE = sizeof(std::uint32_t);

public:
    static void printBytes(const std::uint32_t& value) {
        // std::uint32_tをstd::uint8_t型に変換することで
        // メモリ内の各バイトに個別にアクセスできるようになる。
        // std::uint32_tは4バイト、std::uint8_tは1バイトなので、
        // このキャストにより、4つの連続したstd::uint8_tとして
        // メモリを読み取ることができるようになる。
        const auto* ptr = reinterpret_cast<const std::uint8_t*>(&value);
        std::array<std::uint8_t, UINT32_SIZE> bytes;
        std::copy(ptr, ptr + UINT32_SIZE, bytes.begin());

        for (const auto& byte : bytes) {
            std::cout << std::hex << std::setw(2) << std::setfill('0')
                << static_cast<int>(byte) << ' ';
        }
        std::cout << std::dec << std::endl;
    }

    static void demostrateByteOrder() {
        const std::uint32_t num = 0x12345678;

        std::cout << "オリジナル値: ";
        printBytes(num);

        std::cout << "リトルエンディアン: ";
        printBytes(num);

        const std::uint32_t big_endian = htonl(num);
        std::cout << "ビッグエンディアン(ネットワークバイトオーダー): ";
        printBytes(big_endian);
    }
};

int main() {
    ByteOrderDemo::demostrateByteOrder();
    return 0;
}



