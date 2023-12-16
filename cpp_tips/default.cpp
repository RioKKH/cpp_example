#include <iostream>

class MyClass {
public:
    // デフォルトコンストラクタを明示的にデフォルト実装に設定
    MyClass() = default;

    // デフォルトデストラクタを明示的にデフォルト実装に設定
    ~MyClass() = default;

    // コピーコンストラクタをデフォルト実装に設定
    MyClass(const MyClass&) = default;

    // コピー代入オペレータをデフォルト実装に設定
    MyClass& operator=(const MyClass&) = default;

    // ムーブコンストラクタをデフォルト実装に設定
    MyClass(MyClass&&) = default;

    // ムーブ代入オペレータをデフォルト実装に設定
    MyClass& operator=(MyClass&&) = default;

    // その他のメンバ関数
    void display() {
        std::cout << "MyClass instance" << std::endl;
    }
};

int main() {
    MyClass obj1;           // デフォルトコンストラクタが呼ばれる
    MyClass obj2 = obj1;    // コピーコンストラクタが呼ばれる
    MyClass obj3;           // デフォルトコンストラクタが呼ばれる
    obj3 = obj1;            // コピー代入オペレータが呼ばれる

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}


