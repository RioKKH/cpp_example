#include <iostream>
#include <list>

template <typename T>
void print_list(const std::list<T>& l)
{
    std::cout << "size of list: " << l.size() << std::endl;
    for (auto it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/*
 * listは双方向リンクで一本の鎖を構成している為、
 * 要素の削除や順序の入れ替えをポインターの張替えで実現できる。
 * 従って、std::vector()ではできなかった様々な操作がメンバー関数
 * として定義されている。
 */

int main()
{
    std::list<int> il = {1, 2, 3};
    print_list(il);

    il.pop_back();
    print_list(il);

    il.push_back(3);
    print_list(il);

    il.push_front(0);
    print_list(il);

    il.emplace_front(-1);
    print_list(il);

    il.pop_front();
    print_list(il);

    return 0;
}
