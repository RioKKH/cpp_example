#include <iostream>

// 関数の宣言
// 引数としてvoid*型のポインタを受け取り、void*型のポインタを返す関数
void *some_function(void *arg) {
    std::cout << "Hello from some_function" << std::endl;
    return nullptr;
}

// 関数ポインタの宣言
void *(*func_ptr)(void *);

int main() {
    // 関数ポインタに関数のアドレスを代入
    func_ptr = &some_function;
    // または、単に以下のように書いてもよい
    // func_ptr = some_function;

    // 関数ポインタを使用して関数を呼び出す
    void *result = (*func_ptr)(nullptr);

    return 0;
}
