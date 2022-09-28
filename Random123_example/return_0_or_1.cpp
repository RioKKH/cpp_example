#include <iostream>
#include <cstdio>
#include "Random123/philox.h"

typedef r123::Philox2x32 RNG_2x32;
typedef r123::Philox2x32 RNG_4x32;

RNG_2x32::ctr_type generateTwoRndValues(unsigned int key,
                                        unsigned int counter)
{
    RNG_2x32 rng;
    // philox2x32_key_t k = philox2x32keyinit(key);
    return rng({0, counter}, {key});
}

void generateFirstPopulation(unsigned int randomSeed)
{
    for (int i = 0; i < 100; ++i)
    {
        const RNG_2x32::ctr_type randomValues = generateTwoRndValues(i, randomSeed);
        printf("### 64 ###\n");
        std::int64_t j64 = randomValues.v[0];
        std::int64_t k64 = randomValues.v[1];
        std::int64_t jj64 = randomValues.v[0] % 2;
        std::int64_t kk64 = randomValues.v[1] % 2;
        printf("%ld,%ld,%ld,%ld\n", j64, jj64, k64, kk64);
        printf("%lx,%lx,%lx,%lx\n", j64, jj64, k64, kk64);

        printf("### 32 ###\n");
        std::int32_t j32 = randomValues.v[0];
        std::int32_t k32 = randomValues.v[1];
        std::int32_t jj32 = randomValues.v[0] % 2;
        std::int32_t kk32 = randomValues.v[1] % 2;
        printf("%ld,%ld,%ld,%ld\n", j32, jj32, k32, kk32);
        printf("%x,%x,%x,%x\n", j32, jj32, k32, kk32);
    }
}

int main()
{
    generateFirstPopulation(0xffddee);
    return 0;
}
