#include <algorithm>
#include <iostream>

struct array_int_3
{
    int storage[3];

    array_int_3(array_int_3 const &other)
    {
        std::copy(std::begin(other.storage),
                  std::end(other.storage),
                  std::begin(storage));
    }
};

struct array_int_10
{
    int storage[10];

    int &operator [](std::size_t i)
    {
        return storage[i];
    }
};

int main()
{
    array_int_10 a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    a[3] = 0;
    std::cout << a[6];
}

