#include <iostream>
#include <limits>

int main()
{
    int max_int = std::numeric_limits<int>::max();
    max_int = max_int + 1;
    std::cout << "Max int + 1: " << max_int << std::endl;
    return 0;
}
