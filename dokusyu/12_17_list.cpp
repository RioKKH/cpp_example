#include <iostream>
#include <list>
#include <iterator> // std::advance()用

template <typename T>
void print_list(const std::list<T> l)
{
    for (const auto& e : l)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

/*
 *  std::listは双方向イテレータ
 */

int main()
{
    // クラステンプレートの型推論を使って<T>を省略することもできる
    std::list<int> l = {1, 5, 9};
    print_list(l); // 1 5 9

    l.insert(l.begin(), 0); // 0 1 5 9
    l.insert(l.end(), 10); // 0 1 5 9 10
    print_list(l); // 0 1 5 9 10

    auto iter = l.begin();
    std::advance(iter, 2); // iterを2つ進める
    l.insert(iter, 2, 3); // iterの位置に2個3を挿入する
    print_list(l);

    int ia[] = {6, 7, 8};
    std::advance(iter, -2); // 2つ戻る

    l.insert(iter, ia, ia + 3);
    print_list(l);

    for (auto it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
