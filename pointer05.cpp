// 配列へのポインター


void test()
{
    using pointer_to_array_type = int (*)[5];

    int a[5];
    pointer_to_array_type = &a;
}

void test2()
{
    int a[5];
    int (*p)[5] = &a;
}

void test3()
{
    int a[5] = {1, 2, 3, 4 ,5};

    // &a[0]と同じ
    int *ptr = a;
    // 配列名が配列の先頭要素へのポインターに暗黙に変換される
}
