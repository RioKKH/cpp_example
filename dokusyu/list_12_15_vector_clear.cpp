#include <iostream>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& v)
{
    for (const auto& i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "Original vector:" << std::endl;
    print_vector(v);

    v.clear(); // 全削除
    std::cout << "Cleared out" << std::endl;
    print_vector(v);

    return 0;
}

