#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int x = 0b00001111;

    cout << "x = " << bitset<8>(x) << endl;
    cout << endl;

    cout << "n番目のビットの設定" << endl;
    cout << "x | (1<<4) = " << bitset<8>(x|1<<4) << endl;
    cout << "x | (1<<5) = " << bitset<8>(x|1<<5) << endl;

    cout << endl;

    cout << "n番目のビットの解除" << endl;
    cout << "x & ~(1<<0) = " << bitset<8>(x & ~(1<<0)) << endl;
    cout << "x & ~(1<<1) = " << bitset<8>(x & ~(1<<1)) << endl;
    cout << "x & ~(1<<2) = " << bitset<8>(x & ~(1<<2)) << endl;
    
    cout << endl;

    cout << "n番目のビットのトグル" << endl;
    cout << "x ^ (1<<0)" << bitset<8>(x ^ (1<<0)) << endl;
    cout << "x ^ (1<<1)" << bitset<8>(x ^ (1<<1)) << endl;
    cout << "x ^ (1<<2)" << bitset<8>(x ^ (1<<2)) << endl;


    cout << "2を掛ける" << endl;
    cout << "x << 1 = " << bitset<8>(x << 1) << endl;
    cout << "2で割る" << endl;
    cout << "x >> 1 = " << bitset<8>(x >> 1) << endl;
    cout << "2のm乗を掛ける" << endl;
    cout << "x << 3 = " << bitset<8>(x << 3) << endl; 
    cout << "2のm乗で割る" << endl;
    cout << "x >> 3 = " << bitset<8>(x >> 3) << endl; 

    return 0;
}
