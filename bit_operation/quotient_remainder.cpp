#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
    int num = 256;
    int CHROMOSOME = 0;

    int quotient  = 0;
    int remainder = 0;

    if ( (num <=  0) || ((1 << 10) < num) )
    {
        std::cout << "Invalid argument" << std::endl;
        exit(1);
    }
        
    for (int i = 5; i <= 10; ++i)
    {
        if (num == (1 << i))
        {
            CHROMOSOME = (1 << i);
        }
        else if (( (1 << i) < num ) && ( num < (1 << (i + 1)) ))
        {
            CHROMOSOME = (1 << (i + 1));
        }
    }
    std::cout << num << ":" << CHROMOSOME << std::endl;
    return 0;
}

