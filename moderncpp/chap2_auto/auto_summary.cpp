#include <vector>
#include <iostream>

int main()
{
    auto x = 10;
    std::cout << x << std::endl;

    std::vector<int> vec{1, 2, 3};
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }
    for (auto itr = vec.begin(); itr != vec.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }

    return 0;
}
