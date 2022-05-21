#include <iostream>
#include <string>

class PrintSpool
{
public:
    PrintSpool()
    {
        std::cout << "initialize" << std::endl;
    }

    void setSpool(std::string printData)
    {
        std::cout << "バッファにデータを格納しました: " << printData << std::endl;
        // 実際ならばここでバッファへの格納処理とプリンタへの印字要求を行う
        return;
    }
};

class Process
{
private:
    PrintSpool *spooler;

public:
    Process(PrintSpool *spool) : spooler(spool)
    {
    }

    void printOut(std::string printData)
    {
        spooler->setSpool(printData);
    }
};

int main(int argc, char **argv)
{
    PrintSpool *pPrintSpool = new PrintSpool();
    Process *pProcA = new Process(pPrintSpool);
    Process *pProcB = new Process(pPrintSpool);
    Process *pProcC = new Process(pPrintSpool);

    pProcA->printOut("Singleton Pattern");
    pProcB->printOut("しんぐるとんぱたーん");
    pProcC->printOut("シングルトンパターン");

    delete pProcA;
    delete pProcB;
    delete pProcC;
    delete pPrintSpool;

    return 0;
}
