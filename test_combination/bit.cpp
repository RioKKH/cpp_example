#include <iostream>
#include <bitset>

const unsigned int BIT_FLAG_0 = (1 << 0); // 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 1000
const unsigned int BIT_FLAG_A = (0b1111);

int main()
{
    int x = 0b0000;
    
    std::cout << "x = " << std::bitset<4>(x) << std::endl;

    x |= BIT_FLAG_0;
    std::cout << "x = " << std::bitset<4>(x) << std::endl;
    x |= BIT_FLAG_1 | BIT_FLAG_2 | BIT_FLAG_3;
    std::cout << "x = " << std::bitset<4>(x) << std::endl;

    if ((x & BIT_FLAG_A) == BIT_FLAG_A)
    {
        std::cout << std::bitset<4>(x & BIT_FLAG_A) << std::endl;
        std::cout << std::bitset<4>(BIT_FLAG_A) << std::endl;
        std::cout << "Yes!!" << std::endl;
    }

    return 0;
}
