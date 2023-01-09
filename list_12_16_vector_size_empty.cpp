#include <iostream>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& v)
{
    std::cout << "v.size(): " << v.size() << std::endl;
    if (v.empty())
    {
        std::cout << "There is nothing to print out." << std::endl;
    }
    else
    {
        for (const auto& i : v)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

/*
 * size(), empty()
 * size()は引数のコンテナの要素数を返す
 * empty()はコンテナが空、つまりsize() == 0の時にtrueを返す
 */

int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4};
    print_vector(v);

    v.erase(v.begin() + 2);
    print_vector(v);

    v.erase(v.end() - 2, v.end());
    print_vector(v);

    v.clear();
    print_vector(v);
    if (v.empty())
    {
        std::cout << "vは空です" << std::endl;
    }

    return 0;
}
