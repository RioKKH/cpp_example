#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::right << std::oct
              << std::setw(8) << std::setfill('0')
              << 1234 << std::endl;
    return 0;
}
