 #include <iostream>

int main() {
    int a = 5; // 'a' は左辺値
    int &ref = a; // 左辺値参照

    // 右辺値
    int b = a + 3;

    // コメントアウトされた行はコンパイルエラーになる例
    // int &ref2 = a + 3; // 右辺値は左辺値参照には割り当てられない

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    return 0;
}
