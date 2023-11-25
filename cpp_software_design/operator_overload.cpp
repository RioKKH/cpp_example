#include <iostream>

class MyClass {
private:
    int value;
public:
    MyClass(int v) : value(v) { }
    // friend関数としてオペレータ<<をオーバーロードする
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj);
};
    
// ユーザー定義型オブジェクトを標準入出力ストリームに直接挿入、または抽
// することが出来るようになる
// オペレータ<<の定義
std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << obj.value; // プライベートメンバにアクセスする
    return os;
}


int main() {
    MyClass myObject(10);
    // オペレータ<<を使用
    std::cout << "myObject: " << myObject << std::endl;
    return 0;
}




