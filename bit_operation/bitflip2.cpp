#include <iostream>
#include <bitset>

int main()
{
    std::int32_t bitarray[] = {1, 1, 1, 1, 1};

    std::cout << "before" << std::endl;
    for (const auto& a : bitarray) std::cout << a << std::endl;

    std::cout << "index: " << 11 % 2 << std::endl;
    std::cout << "index: " << 10 % 2 << std::endl;
    bitarray[static_cast<std::int32_t>(11 % 2)] ^= 1;
    bitarray[static_cast<std::int32_t>(10 % 2)] ^= 1;

    std::cout << "after" << std::endl;
    for (const auto& a : bitarray) std::cout << a << std::endl;

    return 0;
}
