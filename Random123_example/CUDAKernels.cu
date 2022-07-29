#include <cuda.h>
#include "Random123/philox.h"
#include "CUDAKernels.hpp"

using namespace r123;

/// Datatype for two 32b random values.
typedef r123::Philox2x32 RNG_2x32;

/// Datatype for four 32b random values.
typedef r123::Philox4x32 RNG_4x32;

/**
 * Generate two random values
 * @param [in] key     - Key for the generator.
 * @param [in] counter - Counter for the generator.
 * @return two random values
 */
__device__ RNG_2x32::ctr_type generateTwoRndValues(unsigned int key,
                                                   unsigned int counter);

/**
 * Device random number generator
 * 
 */
inline __device__ RNG_2x32::ctr_type generateTwoRndValues(unsigned int key,
                                                          unsigned int counter)
{
    RNG_2x32 rng;

    return rng({0, counter}, {key});
} // end of TwoRandomINTs


/**
 * Initialize Population before run.
 */
__global__ void cudaGenerateRandomNumberKernel(float *rand1,
                                               float *rand2,
                                               unsigned int randomSeed)
{
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    const int nGenes = 100;

    // while (idx < nGenes)
    // {
    const RNG_2x32::ctr_type randomValues = generateTwoRndValues(idx, randomSeed);
    printf("%d,%d\n", randomValues.v[0], randomValues.v[1]);
    rand1[idx] = randomValues.v[0];
    rand2[idx] = randomValues.v[1];
    // }
}

__global__ void cudaTest()
{
    printf("hello GPU\n");
}

