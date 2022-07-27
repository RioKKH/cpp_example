#include "Random123/philox.h"


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
__global__ void cudaGenerateFirstPopulationKernel(unsigned int randomSeed)
{
    size_t i = threadIdx.x + blockIdx.x * blockDim.x;
    size_t stride = blockDim.x * gridDim.x;

    const int nGenes = 100;

    while (i < nGenes)
    {
        const RNG_2x32::ctr_type randomValues = generateTwoRndValues(i, randomSeed);


