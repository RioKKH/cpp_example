#include <iostream>
#include <string>

class PrintSpool final
{
private:
    PrintSpool() = default; // コンストラクタをprivateに置く
    ~PrintSpool() = default; // デストラクタをprivateに置く

public:
    PrintSpool(const PrintSpool& obj) = delete; // コピーコンストラクタをdelete指定
    PrintSpool& operator=(const PrintSpool& obj) = delete; // コピー代入演算子もdelete指定
    PrintSpool(PrintSpool&&) = delete; // ムーブコンストラクタをdelete指定
    PrintSpool& operator=(PrintSpool&&) = delete; // ムーブ代入演算子をdelete指定

    static PrintSpool& getInstance()
    // static PrintSpool* getInstance()
    {
        static PrintSpool instance; // privateなコンストラクタを呼び出す
        return instance;
        // return &instance;
    }

    void setSpool(std::string printData)
    {
        std::cout << "バッファにデータを格納しました" << std::endl;
        std::cout << printData << std::endl;
        return;
    }
};

class Process
{
public:
    Process() {};
    void printOut(std::string printData)
    {
        PrintSpool::getInstance().setSpool(printData);
        // PrintSpool::getInstance()->setSpool(printData);
    }
};

int main(void)
{
    // Process procA;
    // procA.printOut("Singleton pattern");
    // PrintSpool::getInstance().setSpool("aaa");
    Process *pProcA = new Process();
    Process *pProcB = new Process();
    Process *pProcC = new Process();

    pProcA->printOut("SingleTon Pattern");
    pProcB->printOut("しんぐるとんぱたーん");
    pProcC->printOut("シングルトンパターン");

    delete pProcA;
    delete pProcB;
    delete pProcC;

    return 0;
}
