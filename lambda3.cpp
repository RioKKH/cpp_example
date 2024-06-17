#include <iostream>
#include <string>

/**
 * コピーキャプチャー
 * ラムダ式は書かれている関数のローカル変数を使うことが出来る。
 * これをキャプチャーという。
 * コピーキャプチャーは変数をコピーによってキャプチャーする
 */

void f()
{
    // ローカル関数
    std::string message = "hello in f()";
    int x = 0;
    [=](){ std::cout << message; }();
    // コピーキャプチャーした変数はラムダ式の中で変更出来ない
    // [=](){ x = 0; }(); // error
}

int main()
{
    f();
    return 0;
}

