#include <iostream>
#include <bitset>

int main(int argc, char const *argv[]) {
    unsigned int value = 1234;
    unsigned int mask = 0b00000000000000001;
    std::cout << std::bitset<32>(value) <<std::endl;
    std::cout << std::bitset<64>(value | mask) << std::endl;
    return 0;
}
