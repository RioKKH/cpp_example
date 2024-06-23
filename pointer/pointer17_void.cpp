#include <iostream>

void test1()
{
    return static_cast<void>(123);
}

void test2()
{
    int data {};

    // int * から void * への変換
    void *ptr = &data;
}

void test3()
{
    int data = 123;
    // int data {};
    void *void_ptr = &data;
    // 一度voidを指すとしたポインターを、intを差し戻すとすると
    int *int_ptr = static_cast<int *>(void_ptr);
    std::cout << *int_ptr << std::endl; // 123
}

void test4()
{
    // 型の異なるポインター間の型変換で
    int data = 456;
    int const *int_const_ptr = &data;
    void const *void_const_ptr = int_const_ptr;
    int const *original = static_cast<int const *>(void_const_ptr);
    std::cout << *original << std::endl;
}


int main()
{
    test1();
    // C++17ではvoid型の変数は作れない
    // void v = test() // error
    test2();
    test3();
    test4();
}

