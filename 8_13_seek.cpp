#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream out{"hello_seek.txt"};

    std::cout << "現在位置: " << out.tellp() << std::endl;
    out << "Hello, File IO" << std::endl;
    std::cout << "現在位置: " << out.tellp() << std::endl;

    out.seekp(7); // 7バイト目に移動

    std::cout << "現在位置: " << out.tellp() << std::endl;
    out << "File Seek" << std::endl; // 上書き
    std::cout << "現在位置: " << out.tellp() << std::endl;

    out.close();

    std::ifstream in{"hello_seek.txt"};

    std::cout << "現在位置: " << in.tellg() << std::endl;
    in.seekg(in.tellg() + std::streamoff{12}); // 現在の位置から12バイト後ろにシーク
    std::cout << "現在位置: " << in.tellg() << std::endl;

    std::string line;
    std::getline(in, line);

    std::cout << line << std::endl;
}
