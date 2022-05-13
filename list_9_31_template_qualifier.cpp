#include <iostream>

template <typename T>
class A
{
public:
    A() {};

    template <typename U> A(A<U>) {};
    template <typename U> using rebind = A<U>;
    template <typename U> 
    void foo()
    {
        std::cout << "A<T>::foo<U>()" << std::endl;
    }

};

