#include <iostream>
#include <vector>

template <typename T>
void print_vector(const std::vector<T> v)
{
    for (const auto& e : v)
    {
        std::cout << e << std::endl;
    }
}

int main()
{
    std::vector<int> iv = {1, 2, 3, 4, 5};
    print_vector(iv);

    return 0;
}
