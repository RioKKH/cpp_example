#include <iostream>
#include <fstream>

int main()
{
    // __FILE__はファイル名に置き換わる識別子
    // ソースファイル自信を出力するプログラムのことをクワイン Quine とよぶが
    // この例のようにファイルストリームを使った場合には一般にはクワインとは
    // みなされない
    std::ifstream in{__FILE__};

    std::string line;
    while (!in.eof())
    {
        std::getline(in, line);
        std::cout << line << std::endl;
    }
}
