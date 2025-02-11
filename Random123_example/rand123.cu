#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include "CUDAKernels.hpp"
#include "Random123/philox.h"

typedef r123::Philox2x32 RNG_2x32;
typedef r123::Philox4x32 RNG_4x32;

__global__ void cudaKernelGenerateRandomNumber(unsigned int randomseed)
{
    uint32_t idx = threadIdx.x + blockIdx.x * blockDim.x;
    printf("%d\n", idx);
    RNG_4x32 rng_4x32;
    RNG_4x32::key_type key
        = {{static_cast<unsigned int>(threadIdx.x),
            static_cast<unsigned int>(blockIdx.x)}};
    RNG_4x32::ctr_type ctr = {{0, 0, randomseed, 0xbeeff00d}};
    RNG_4x32::ctr_type randomValues;

    ctr.incr();
    randomValues = rng_4x32(ctr, key);
    printf("%d,%d,%d,%d\n", randomValues[0], randomValues[1], randomValues[2], randomValues[3]);
    __syncthreads();
}


int main(int argc, char* argv[])
{
    unsigned int seed = 999;
    uint32_t blocknum = 16;
    uint32_t threadnum = 16;

    printf("Start\n");
    cudaKernelGenerateRandomNumber<<<blocknum, threadnum>>>(seed);
    printf("End\n");

    return 0;
}
