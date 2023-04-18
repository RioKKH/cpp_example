#include <vector>
#include <iostream>

// エイリアステンプレート alias template
// この型はTに依存するのでtypenameが必要
template <typename T>
using vector_reference = typename std::vector<T>::reference;

template <typename T>
vector_reference<T> // Tを使っているが、エイリアスの中で依存名が解決しているのでここでは不要
at(std::vector<T>& v, std::size_t i)
{
    return v[i];
}

int main()
{

    std::vector<int> v = {0, 1, 2, 3};
    std::vector<int>::reference r = at(v, 0);
    std::cout << r << std::endl;

    return 0;
}

