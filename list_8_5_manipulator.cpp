#include <iostream>
#include <iomanip> // 入出力マニピュレーターを使用するために必要

int main()
{
    // std::hexマニピュレーターによって16進数での表示に切り替わる
    std::cout << std::hex << 1234 << std::endl;

    // マニピュレータで浮動小数点数の精度を変更する
    std::cout << std::setprecision(6) << 1234.5678f << std::endl;

    // フラグをセットしても、マニピュレーターでクリア出来る
    std::cout.setf(std::ios::boolalpha);
    std::cout << std::noboolalpha << true << std::endl;
}
