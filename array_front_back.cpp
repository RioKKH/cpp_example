#include <iostream>
#include <array>

template <typename T, std::size_t N>
struct array
{
    T storage[N];

    using reference = T &;
    using const_reference = T const &;
    // using const_reference = const T &;

    reference front()
    {
        std::cout << "非const版" << std::endl;
        return storage[0];
    }

    const_reference front() const
    {
        std::cout << "const版" << std::endl;
        return storage[0];
    }

    reference back()
    {
        std::cout << "非const版" << std::endl;
        return storage[N-1];
    }

    const_reference back() const
    {
        std::cout << "const版" << std::endl;
        return storage[N-1];
    }
};

int main()
{

    // 非const版
    array<int, 5> a = {1, 2, 3, 4 ,5};
    // std::array<int, 5> a = {1, 2, 3, 4, 5}; // std::arrayを使う場合

    int &f = a.front(); // 1
    int &b = a.back();
    std::cout << f << ", " << b << std::endl;

    // const版
    const array<int, 5> A = {1, 2, 3, 4 ,5};
    // const std::array<int, 5> A = {1, 2, 3, 4, 5};
    int const &cf = A.front();
    int const &cb = A.back();
    std::cout << cf << ", " << cb << std::endl;
}
