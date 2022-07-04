#include <iostream>
#include <string>
#include <memory>

int main()
{
    std::unique_ptr<std::string> pStr(new std::string("test"));

    // operator *()でstring型を参照
    // "test"と表示される
    std::cout << *pStr << std::endl;

    // operator->()でstring型のsize関数を呼び出せる
    unsigned int StrSize = pStr->size();
    std::cout << StrSize << std::endl;
}
