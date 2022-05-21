#include <iostream>
#include <string>

class PrintSpool final
{
private:
    // 外部のクラスがPrintSpoolクラスのオブジェクトをnew出来ないようにする
    // コンストラクタをprivateにする
    PrintSpool() = default; // コンストラクタをprivateに置く
    ~PrintSpool() = default; // デストラクタをprivateに置く

public:
    // 代入によるコピーも可能なため、コピーコンストラクタと代入演算子をdelete指定する
    PrintSpool(const PrintSpool& obj) = delete; // コピーコンストラクタをdelete指定
    PrintSpool& operator=(const PrintSpool& obj) = delete; // コピー代入演算子もdelete指定
    PrintSpool(PrintSpool&&) = delete; // ムーブコンストラクタをdelete指定
    PrintSpool& operator=(PrintSpool&&) = delete; // ムーブ代入演算子をdelete指定

    // 唯一のPrintSpoolオブジェクトを提供するためのgetInstance()クラスメソッドを準備する
    // instanceというstatic変数に保持しているPrintSpoolオブジェクトのポインタを返す。
    // instanceは、初めてgetInstance()が呼び出されたときに、PrintSpoolのインスタンスを
    // 持つため、不変で唯一のオブジェクトが保証される。
    static PrintSpool& getInstance()
    // static PrintSpool* getInstance() // ポインタで定義する場合
    {
        static PrintSpool instance; // privateなコンストラクタを呼び出す
        return instance;
        // return &instance; // ポインタで定義した場合
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
        // PrintSpool::getInstance()->setSpool(printData); // ポインタで定義した場合
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
