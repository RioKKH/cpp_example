#include <iostream>
#include <string>

// primary template
template <typename T>
class A
{
public:
    std::string name() const
    {
        return "Aのプライマリーテンプレート";
    }

    void common_method()
    {
        std::cout << "共通動作" << std::endl;
    }
};

// explicitly specialized template
template<>
class A<int>
{
public:
    std::string name() const
    {
        return "Aをintで明示的特殊化したテンプレート";
    }

    // プライマリテンプレートと全く同じ動作をする場合でも、
    // 明示的特殊化したテンプレートでも定義する必要がある
    void common_method()
    {
        std::cout << "共通動作" << std::endl;
    }
};

int main()
{
    A<float> f; // プライマリテンプレートが使われる
    std::cout << f.name() << std::endl;

    A<int> i; // 明示的特殊化したテンプレートが使われる
    std::cout << i.name() << std::endl;
}
