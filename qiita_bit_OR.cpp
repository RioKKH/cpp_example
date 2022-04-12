#include <iostream>

using namespace std;

int main()
{
    int a = 45; // 実際上は0b101101、あるいは0x2dと書く
    int b = 25;

    cout << a << " OR " << b << " = " << (a|b) << endl;
}
