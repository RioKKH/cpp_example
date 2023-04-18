#include <iostream>
#include <fstream>

int main()
{
    std::ofstream out{"seek.txt"};
    out << "Hello, world" << std::endl;

    out.seekp(7, std::ios::beg);

    out << "file seek" << std::endl;
}
