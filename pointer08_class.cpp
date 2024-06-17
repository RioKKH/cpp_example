#include <iostream>

auto print = [](auto x){ std::cout << x << std::endl; };

struct Pointer1
{
    int data = 42;
    int *data_member = &data;
    int *member_function()
    {
        return &data;
    }
};

struct Pointer2
{
    int data = 42;
    int member_function()
    {
        print(data);
        return data;
    }
};

void test1()
{
    Pointer1 pointer;

    // これはOK
    *pointer.data_member = 0;
    int c = *pointer.member_function();
    std::cout << c << std::endl;
}

void test2()
{
    Pointer2 obj;
    Pointer2 *ptr = &obj;
    Pointer2 &ref = *ptr;

    // ポインターを参照する演算子*よりも、演算子ドット.のほうが
    // 演算子の優先順位が高いので、下のようにカッコで括ってやる必要がある。
    (*ptr).data = 0;
    (*ptr).member_function();

    print((*ptr).data);

    ref.data = 1;
    print(ref.data);

    // シンタックスシュガーとして演算子->が準備されている
    // a->bは(*(a))->bと同じ意味
    print(ptr->data);
    ptr->member_function();
}


int main()
{
    test2();
}
