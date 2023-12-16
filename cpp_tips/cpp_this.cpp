#include <iostream>
using namespace std;

class MyClass
{
private:
    int value;

public:
    // コンストラクタ
    MyClass(int value)
    {
        // thisポインタを使ってメンバ変数にアクセス
        // 引数のvalueとメンバ変数のvalueは同じ名前だが、
        // thisポインタを使うことで区別できる
        this->value = value;
    }

    // メンバ変数の値を設定するメソッド
    void setValue(int value)
    {
        this->value = value;
    }

    // メンバ変数の値を取得するメソッド
    // const修飾子をつけることで、メンバ変数の値を変更しないことを明示する。
    // また、const修飾子をつけることで、const修飾子がついていないメソッドから
    // 呼び出すことができる。つまり、const修飾子をつけることで、メソッドの
    // 呼び出しを制限することができる。このようなメソッドをconstメソッドと呼ぶ。
    int getValue() const
    {
        return this->value;
    }

    // メソッドチェーンを実現するメソッド
    MyClass& increment()
    {
        this->value++; // メンバ変数の値をインクリメント
        return *this;  // thisのデリファレンスを返す
    }
};

int main()
{
    MyClass obj(10);

    cout << "初期値: " << obj.getValue() << endl;

    obj.setValue(20);
    cout << "新しい値: " << obj.getValue() << endl;

    obj.increment().increment().increment(); // メソッドチェーンの使用
    cout << "3回インクリメント後: " << obj.getValue() << endl;

    return 0;
}
