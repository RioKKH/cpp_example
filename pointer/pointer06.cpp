#include <iostream>

// templateをエイリアス宣言に用いる

template <typename T> using type = T;
template <typename T> using add_pointer_t = T *;

void test1()
{

    // int *
    type<int> *a = nullptr;

    // int (*)(int)
    type<int(int)> *b = nullptr;

    // int (*)[5]
    type<int[5]> *c = nullptr;

}

//- 最初からポインターを返すエイリアス宣言をする
void test2()
{
    // int *
    add_pointer_t<int> a = nullptr;

    // int **
    add_pointer_t<int *> b = nullptr;
    // add_pointer_t<add_pointer_t<int>> a = nullptr;

    // int(*)(int)
    add_pointer_t<int (int)> c = nullptr;

    // int(*)[5]
    add_pointer_t<int [5]> d = nullptr;
}


