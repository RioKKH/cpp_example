#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4};
    for (auto iter = v.begin(); iter != v.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}
