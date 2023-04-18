#include <iostream>

template <typename T>
class A
{
public:
    void foo()
    {
        std::cout << "foo" << std::endl;
    }
};

int main()
{
    A<int> a;
    a.foo();
}

