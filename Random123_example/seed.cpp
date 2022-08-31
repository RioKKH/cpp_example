#include <sys/time.h>
#include <iostream>

unsigned int get_randomseed()
{
    struct timeval tp1;
    gettimeofday(&tp1, nullptr);
    unsigned int randomeseed = tp1.tv_sec/2 * tp1.tv_usec;
    // unsigned int randomeseed = (tp1.tv_sec / 2) * tp1.tv_usec;

    return randomeseed;
}


int main()
{
    int N = 10000;
    for (int i = 0; i < N; ++i)
    {
        std::cout << get_randomseed() << std::endl;
    }
    return 0;
}
