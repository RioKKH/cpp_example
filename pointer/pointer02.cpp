#include <iostream>

auto print = [](auto x){ std::cout << x << std::endl; };

// ぽいんたーへのポインター
void test1()
{
    // 適当なU型
    using U = int;
    // ポインターとしてのT型
    using T = U *;
    // T型へのポインター型
    // つまりU型へのポインター型へのポインター型
    // つまりU **
    using type = T *;

    {
        // int
        int x = 123;
        print(x);

        // pointer to int
        int *p = &x;
        print(*p);

        // pointer to pointer to int
        int **pp = &p;
        print(**pp);

        // 123
        // ポインターを経由したポインターを経由したXの読み込み
        int value1 = **pp; // 2回operator *を用いれば良い。
        print(value1);

        int y = 456;
        print(y);

        // ポインターを経由した変数pの変更
        *pp = &y;
        print(&y);
        print(*pp);
        print(**pp);

        // 456
        // ポインターを経由したポインターを経由したyの読み込み
        int value2 = **pp;
        print(value2);
    }
}

void test2()
{
    int object = 123;
    print(&object);
    print(object);

    int *a = &object; // objectのメモリーアドレスを指している
    print(a);
    print(*a);

    int **b = &a;
    print(b); // aのメモリーアドレスを指している
    print(*b); // objectのメモリーアドレスを指している
    print(**b); // objectの値そのもの

    // cとaは同じ値-->同じメモリーアドレスを指している
    int *c = *b;
    print(c); // objectのメモリーアドレスを指している

    // objectに1が代入される
    *c = 1;
    // objectに2が代入される
    **b = 2;
}

//- referenceを使う場合
void test3()
{
    int object = 123;
    print(&object);
    print(object);

    int *a = &object;
    int **b = &a;

    int &r1 = *a; // objectのリファレンス
    print(a);   // objectのメモリ−アドレス
    print(&r1); // objectのメモリーアドレス
    print(&a);  // objectの値
    print(&r1); // objectの値

    // objectに1が代入される
    r1 = 1;
    print(r1);
    print(object);

    int &r2 = **b;
    print(&r2); // objectのメモリーアドレス
    print(r2);  // objectの値

    r2 = 2;
    print(object); // objectに2が代入される
    print(r2);
}


int main()
{
    test1();
    test2();
    test3();
}

