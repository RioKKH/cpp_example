#include <iostream>
#include <cstdio>
#include "Random123/philox.h"

typedef r123::Philox2x32 RNG_2x32;
typedef r123::Philox2x32 RNG_4x32;

RNG_2x32::ctr_type generateTwoRndValues(unsigned int key,
                                        unsigned int counter)
{
    RNG_2x32 rng;
    return rng({0, counter}, {key});
}

void generateFirstPopulation(unsigned int randomSeed)
{
    for (int i = 0; i < 100; ++i)
    {
        const RNG_2x32::ctr_type randomValues = generateTwoRndValues(i, randomSeed);
        int j = randomValues.v[0];
        int k = randomValues.v[1];
        int jj = randomValues.v[0] % 2;
        int kk = randomValues.v[1] % 2;
        printf("%d,%d,%d,%d\n", j, jj, k, kk);
        // std::cout << j << "," << k << std::endl;
    }
}

int main()
{
    generateFirstPopulation(1);
    return 0;
}
