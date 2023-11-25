#include <iostream>

// クラスの宣言
class Box {
private:
    int width;

public:
    // explicitは付けた方が良いという話がC++の本に書いてあった。
    // これは付けないと暗黙的な変換が行われるので、それを回避するためである。
    // 例えば、Box b = 10; と書いた場合、10がBoxのコンストラクタに渡されて、
    // Box b = Box(10); と同じ意味になる。
    // 一方でexplicitを付けると、コンストラクタの引数に10が渡されることはなくなる
    // そのため、Box b = 10; と書いた場合、コンパイルエラーになる
    explicit Box() : width(0) { }  // コンストラクタ
    friend void displayBox(Box& b); // friend関数の宣言
};

// friend関数の定義
void displayBox(Box& b) {
    // プライベートメンバにアクセスできる
    std::cout << "Box width: " << b.width << std::endl;
}

// メイン関数
int main() {
    Box myBox;
    // friend関数を呼び出す
    displayBox(myBox);
    return 0;
}




