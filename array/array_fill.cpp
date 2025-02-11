#include <iostream>

template <typename T, std::size_t N>
struct array
{
    T storage[N];

    void fill(T const &u)
    {
        for (std::size_t i = 0; i != N; ++i)
        {
            storage[i] = u;
        }
    }
};

int main()
{
    array<int, 5> a = {1, 2, 3 ,4, 5};
    // std::array<int, 5> a = {1, 2, 3 ,4, 5};

    a.fill(0);
}
