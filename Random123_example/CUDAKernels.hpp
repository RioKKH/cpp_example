#ifndef CUDAKERNELS_HPP
#define CUDAKERNELS_HPP

#include <cuda.h>

__global__ void cudaGenerateRandomNumberKernel(float *rand1, float *rand2, unsigned int randomSeed);

__global__ void cudaTest();

#endif // CUDAKERNELS_HPP
