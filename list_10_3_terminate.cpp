#include <iostream>

int main()
{
    throw 0; // 誰もキャッチしない例外

    // std::terminate()が呼ばれてプログラムが強制終了する
    // これ以降の処理は実行されない

    std::cout << "throwの後" << std::endl;
}
