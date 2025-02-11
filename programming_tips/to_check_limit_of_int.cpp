#include <iostream>
#include <limits>

int main(int argc, char const* argv[])
{
    std::cout << "int: " <<
        std::numeric_limits<int>::lowest() << ", " <<
        std::numeric_limits<int>::max() << std::endl;

    std::cout << "long: " <<
        std::numeric_limits<long>::lowest() << ", " <<
        std::numeric_limits<long>::max() << std::endl;

    std::cout << "longlong: " <<
        std::numeric_limits<long long>::lowest() << ", " <<
        std::numeric_limits<long long>::max() << std::endl;

    std::cout << "float: " <<
        std::numeric_limits<float>::lowest() << ", " <<
        std::numeric_limits<float>::max() << std::endl;

    std::cout << "double: " <<
        std::numeric_limits<double>::lowest() << ", " <<
        std::numeric_limits<double>::max() << std::endl;
}
