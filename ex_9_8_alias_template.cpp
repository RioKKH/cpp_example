#include <iostream>

template <typename T>
class A
{
private:
    T value;

public:
    using value_type = T;

    explicit A(T value) : value(value) {}

    T& get_value() { return value; }
};

// エイリアステンプレート alias template
template <typename T>
using A_value = typename A<T>::value_type;

template <typename T>
A_value<T>& get(A<T>& a) // Tを使っているが、エイリアスの中で依存名が解決しているので、ここでは不要
{
    return a.get_value();
}

int main()
{
    A<int> a{42};

    std::cout << get(a) << std::endl;
}
