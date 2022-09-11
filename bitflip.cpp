#include <iostream>
#include <bitset>

using namespace std;

const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 1000 0000


int main()
{
    int a = 3; // 0011

    // bitflip mutation
    cout << bitset<4>(a) << endl;
    cout << bitset<4>(a ^ BIT_FLAG_0) << endl;
    cout << bitset<4>(a ^ BIT_FLAG_1) << endl;
    cout << bitset<4>(a ^ BIT_FLAG_2) << endl;
    cout << bitset<4>(a ^ BIT_FLAG_2 ^ BIT_FLAG_2) << endl;

    return 0;
}


