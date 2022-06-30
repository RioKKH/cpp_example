#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int x = 0x7f51cbff;
	cout << bitset<32>(x) << endl;
    return 0;
}
