#include <iostream>
#include <vector>

template <typename T>
void print_vector(const std::vector<T> v)
{
    for (const auto& e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    print_vector(v);
    v.push_back(6);
    print_vector(v);

    return 0;
}

