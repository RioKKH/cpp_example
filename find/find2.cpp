#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto pos = std::find(std::begin(v), std::end(v), 0);

    if (pos != std::end(v)) 
    {
        std::cout << "Found." << *pos << std::endl;
    }
    else
    {
        std::cout << "Not found." << std::endl;
    }
}
