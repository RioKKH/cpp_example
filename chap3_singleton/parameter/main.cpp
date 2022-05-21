#include <iostream>
#include "Parameters.hpp"

// singletonの練習
class CUDA
{
private:
    int POPSIZE;

public:
    CUDA() {};
    void loadParams(void)
    {
        Parameters::getInstance().loadParams();
    }

    void getPOPSIZE(void)
    {
        POPSIZE = Parameters::getInstance().getPopsize();
    }

    void showPOPSIZE(void)
    {
        std::cout << POPSIZE << std::endl;
    }
};

int main()
{
    std::cout << "pcuda1" << std::endl;
    CUDA *pcuda1 = new CUDA();
    pcuda1->loadParams();
    pcuda1->getPOPSIZE();
    pcuda1->showPOPSIZE();

    std::cout << "pcuda2" << std::endl;
    CUDA *pcuda2 = new CUDA();
    pcuda1->getPOPSIZE();
    pcuda1->showPOPSIZE();
}
    
