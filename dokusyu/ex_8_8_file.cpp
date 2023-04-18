#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::ifstream in{__FILE__};

    // 現在の位置(0バイト目)からファイルの末尾に移動
    in.seekg(0, std::ios::end);

    std::cout << in.rdstate() << std::endl;

    std::cout << "eof: " << std::boolalpha
        << bool(in.rdstate() & std::ios::eofbit) << std::endl;
    std::cout << "fail: " << std::boolalpha
        << bool(in.rdstate() & std::ios::failbit) << std::endl;
    std::cout << "bad: " << std::boolalpha
        << bool(in.rdstate() & std::ios::badbit) << std::endl;

    std::cout << std::endl;

    in.get();

    std::cout << in.rdstate() << std::endl;

    std::cout << "eof: " << std::boolalpha
        << bool(in.rdstate() & std::ios::eofbit) << std::endl;
    std::cout << "fail: " << std::boolalpha
        << bool(in.rdstate() & std::ios::failbit) << std::endl;
    std::cout << "bad: " << std::boolalpha
        << bool(in.rdstate() & std::ios::badbit) << std::endl;
}
