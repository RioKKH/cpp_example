#include <iostream>

template <typename T>
class A
{
public:
    void foo();
};

template <typename T>
void A<T>::foo()
{
    std::cout << "foo() defined outside of class template" << std::endl;
}


int main()
{
    A<int> a;
    a.foo();
}
