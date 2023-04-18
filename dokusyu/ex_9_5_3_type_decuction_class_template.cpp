#include <iostream>

// class template
template <typename T>
class A
{
public:
    void method()
    {
        std::cout << "A<T>::method()" << std::endl;
    }
};

// function template
// 関数の仮引数としてクラステンプレートを取る
template <typename T>
void call_method(A<T> a)
{
    a.method();
}

int main()
{
    A<int> a;
    call_method(a);
}
