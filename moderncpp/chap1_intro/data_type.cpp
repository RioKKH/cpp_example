#include <iostream>
using namespace std;

int main()
{
    // データ型の指定と初期化が切り離されている
    int i;
    double d;
    char *p;

    cout << sizeof(i) << "," << sizeof(d) << "," << sizeof(p) << endl;
    return 0;
}
