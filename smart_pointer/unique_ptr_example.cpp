#include <iostream>
#include <memory>

void set(int *p, int num)
{
    for (int i = 0; i < num; i++) {
        p[i] = i + 1;
    }
}


int main()
{
    {
        int *p = new int(0);
        std::cout << *p << std::endl;
        delete p;
    }
    {
        std::unique_ptr<int>p(new int(1));
        std::cout << *p << std::endl;
    }
    {
        std::unique_ptr<int>p;
        p = std::make_unique<int>(2);
        std::cout << *p << std::endl;
    }
    {
        int  num = 5;
        // 配列の要素を0で初期化
        std::unique_ptr<int[]>p(new int[num] {});
        // 配列の要素を1,2,3,3,4,5で初期化
        // std::unique_ptr<int[]>p(new int[num] {1, 2, 3, 4, 5}); 
        for (int i = 0; i < num; i++) std::cout << p[i] << ' ';
        std::cout << std::endl;
    }
    {
        int num = 5;
        std::unique_ptr<int[]>p;
        p = std::make_unique<int[]>(num); // 0で初期化される
        // この書き方だと所望の数値での初期化はできない
        for (int i = 0; i < num; i++) std::cout << p[i] << ' ';
        std::cout << std::endl;
    }
    {
        int num = 5;
        std::unique_ptr<int[]>p;
        p = std::make_unique<int[]>(num); // 0で初期化される
        set(p.get(), num); // .get()を使うことで、先頭アドレス(生のポインタ)を取得できる
        for (int i = 0; i < num; i++) std::cout << p[i] << ' ';
        std::cout << std::endl;
    }
}
