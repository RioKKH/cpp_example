#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    for (auto i = std::begin(v),
              j = std::end(v); i != j; ++i)
    {
        std::cout << *i;
    }
    std::cout << std::endl;
}

