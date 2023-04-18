#include <iostream>
#include <bitset>

using namespace std;

/**
やりたいこと 	                                    実装
ビット bit に i 番目のフラグが立っているかどうか 	if (bit & (1<<i))
ビット bit に i 番目のフラグが消えているかどうか 	if (!(bit & (1<<i)))
ビット bit に i 番目のフラグを立てる 	            bit｜= (1<<i)
ビット bit に i 番目のフラグを消す 	                bit &= ~(1<<i)
ビット bit に何個のフラグが立っているか 	        __builtin_popcount(bit)
ビット bit に i 番目のフラグを立てたもの 	        bit｜(1<<i)
ビット bit に i 番目のフラグを消したもの 	        bit & ~(1<<i)
*/

// defineで表現する場合
// const unsigned intを使えという意見もあるそう
#define dBIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
#define dBIT_FLAG_1 (1<<1) // 0000 0000 0000 0010
#define dBIT_FLAG_2 (1<<2) // 0000 0000 0000 0100
#define dBIT_FLAG_3 (1<<3) // 0000 0000 0000 1000
#define dBIT_FLAG_4 (1<<4) // 0000 0000 0001 0000
#define dBIT_FLAG_5 (1<<5) // 0000 0000 0010 0000
#define dBIT_FLAG_6 (1<<6) // 0000 0000 0100 0000
#define dBIT_FLAG_7 (1<<7) // 0000 0000 1000 0000

const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000

int main()
{
    // {1, 3, 5} にフラグの立ったビット
    unsigned int bit = BIT_FLAG_1 | BIT_FLAG_3 | BIT_FLAG_5;
    cout << "{1, 3, 5} = " << bitset<8>(bit) << endl;

    // ビット {1, 3, 5}について、3番目のフラグが立っていること
    if (bit & BIT_FLAG_3)
    {
        cout << "3 is in     " << bitset<8>(bit) << endl;
    }

    // ビット {1, 3, 5} について0番目のフラグが立っていないこと
    if (!(bit & BIT_FLAG_0))
    {
        cout << "0 is not in " << bitset<8>(bit) << endl;
    }

}
