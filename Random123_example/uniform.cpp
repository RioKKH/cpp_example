#include <iostream>
#include <cstdio>
#include "Random123/philox.h"
#include "Random123/threefry.h"
#include "Random123/uniform.hpp"

typedef r123::Philox2x32 RNG_2x32;
typedef r123::Philox4x32 RNG_4x32;

template <typename T>
typename r123::make_unsigned<T>::type U(T x) { return x; }

template <typename T>
typename r123::make_signed<T>::type S(T x) { return x; }

template <typename Ftype, typename RNG, typename Utype>
void chk(const std::string& fname,
         const std::string& rngname,
         const std::string& ftypename,
         Utype f)
{
    std::string key = fname + " " + rngname + " " + ftypename;
    RNG rng;
    typedef typename RNG::ukey_type ukey_type;
    typedef typename RNG::ctr_type ctr_type;
    typedef typename RNG::key_type key_type;

    ctr_type c   = {{}};
    ukey_type uk = {{}};
    key_type k = uk;

}


RNG_4x32::ctr_type generateTwoRndValues(unsigned int key,
                                        unsigned int counter)
{
    RNG_4x32 rng;
    // philox2x32_key_t k = philox2x32keyinit(key);
    return rng({0, counter}, {key});
}

void generateFirstPopulation(unsigned int randomSeed)
{
    for (int i = 0; i < 100000; ++i)
    {
        const RNG_4x32::ctr_type randomValues = generateTwoRndValues(i, randomSeed);

        printf("%f\n", r123::u01fixedpt<float>(randomValues.v[0]));
        printf("%f\n", r123::u01fixedpt<float>(randomValues.v[1]));
        printf("%f\n", r123::u01fixedpt<float>(randomValues.v[2]));
        printf("%f\n", r123::u01fixedpt<float>(randomValues.v[3]));
    }
}

int main()
{
    generateFirstPopulation(0xffddee);
    return 0;
}
