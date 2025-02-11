#include <iostream>
#include <string>

struct Object
{
    std::string name;
    // コンストラクター
    Object(std::string const &name) : name(name)
    {
        std::cout << name << " is constructed." << std::endl;
    }

    // デストラクタ−
    ~Object()
    {
        std::cout << name << " is destructed." << std::endl;
    }
};

void f()
{
    Object obj("f");
    throw 0;
}

void g()
{
    Object obj("g");
    f();
}

int main()
{
    // 変数objが構築される
    Object obj("main");

    try {
        g();
    } catch(int e) {
        std::cout << "caught." << std::endl;
    }
}
