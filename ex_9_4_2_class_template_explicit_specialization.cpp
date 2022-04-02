#include <iostream>

// primary template
template <typename T>
class A
{
private:
    T a;
public:
    explicit A(T a) : a{a}
    {
    }

    void show() const
    {
        std::cout << "primary template" << std::endl;
    }
};

// explicitly specialized template
template <>
class A<void>
{
public:
    void show() const
    {
        std::cout << "explicitly specialized template" << std::endl;
    }
};

int main()
{
    A<int> primary{42};
    A<void> specialized;

    primary.show();
    specialized.show();
}


