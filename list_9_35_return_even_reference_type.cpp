#include <iostream>

template <typename T>
class A
{
private:
    T value;

public:
    explicit A(T value) : value{value} {}

    T& get_value() { return value; }
};

// Tが参照型であっても値をコピーしたクラスAを返すようにする
template <typename T>
A<std::remove_const_t<std::remove_reference_t<T>>> make_A(T value)
{
    return A<std::remove_const_t<std::remove_reference_t<T>>>{value};
}

int main()
{
    int i = 42;
    std::cout << &i << std::endl;

    // A<int> r{i};
    // 下の形だと先に確保したiをAのvalueとして利用することになる。
    // 同じメモリーに格納された数値を指すということ
    A<int&> r{i};

    std::cout << r.get_value() << std::endl; // 42
    i = 43;
    std::cout << r.get_value() << std::endl; // 43
    std::cout << &r.get_value() << std::endl;

    // 明示的に参照を使って実体化しても、型特性テンプレートによって値で返すようになる
    auto x = make_A<int&>(i);
    std::cout << &x.get_value() << std::endl;
}

