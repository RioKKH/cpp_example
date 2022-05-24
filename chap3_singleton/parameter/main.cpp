#include <iostream>
#include "Parameters.hpp"
#include "CUDAkernel.hpp"
#include "Misc.hpp"

int main()
{
    std::cout << "pcuda1" << std::endl;
    CUDA *pcuda1 = new CUDA();
    // pcuda1->loadParams();
    pcuda1->getPOPSIZE();
    pcuda1->showPOPSIZE();

    std::cout << "pcuda2" << std::endl;
    CUDA *pcuda2 = new CUDA();
    pcuda1->getPOPSIZE();
    pcuda1->showPOPSIZE();
}
    
