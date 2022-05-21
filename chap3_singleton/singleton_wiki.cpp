#include <iostream>

class Singleton
{
private:
    Singleton() {}; // コンストラクタをprivateに置く
    Singleton(const Singleton&); // コピーコンストラクタもprivateに置き、定義しない
    Singleton& operator=(const Singleton&); // コピー代入演算子もprivateに置き、定義しない
    ~Singleton() {}; // デストラクタをprivateに書く

public:
    static Singleton& getInstance()
    {
        static Singleton inst; // privateなコンストラクタを呼び出す
        return inst;
    }

    const char* getString() const
    {
        return "Hello world!";
    }
};

int main()
{
    std::cout << Singleton::getInstance().getString() << std::endl;

    return 0;
}
