#include <iostream>
using namespace std;

// クラスを定義する
class MyClass {
public:
    MyClass(); // デフォルトコンストラクタ
    int id;
    char name[16];
};

// デフォルトコンストラクタの定義
MyClass::MyClass() {
    id = 0;
    name[0] = '\0';
}

int main()
{
    // クラスのインスタンスを生成する
    MyClass *c = new MyClass();
    // クラスのメンバを出力する
    c->id = 1;
    c->name[0] = 'A';
    cout << c->id << " " << c->name << endl;
    // インスタンスを解放する
    delete c;
    return 0;
}
