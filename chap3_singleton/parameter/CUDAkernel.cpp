#ifndef CUDA_HPP
#define CUDA_HPP

#include <iostream>
#include "CUDAkernel.hpp"
#include "Parameters.hpp"

void CUDA::loadParams(void)
{
    Parameters::getInstance().loadParams();
}

void CUDA::getPOPSIZE(void)
{
    POPSIZE = Parameters::getInstance().getPopsize();
}

void CUDA::showPOPSIZE(void)
{
    std::cout << POPSIZE << std::endl;
}

#endif
