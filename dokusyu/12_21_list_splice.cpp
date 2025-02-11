#include <iostream>
#include <list>
#include <iterator>

template <typename T>
void print_list(const std::list<T>& il)
{
    for (auto iter = il.begin(); iter != il.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

/*
 * list間での要素の移動にはsplice()が使える。
 * void splice(const_iterator pos, std::list<T>& other);
 * void splice(const_iterator pos, std::list<T>& other, const_iterator it);
 * void splice(const_iterator pos, std::list<T>& other, const_iterator first, const_iterator last);
 */

int main()
{
    std::list<int> il0 = {0, 1, 5, 6};
    print_list(il0);
    std::list<int> il1 = {2, 4, 6};
    print_list(il1);
    std::list<int> il2 = {3, 4};
    print_list(il2);

    auto iter = il0.begin(); // iterは0を指す
    std::advance(iter, 2);   // 2つ進めるので、iterは5を指す

    il0.splice(iter, il1, il1.begin()); // il1の先頭要素をiteratorの直前に移動
    il0.splice(iter, il2, il2.begin(), il2.end()); // il2の全要素をiteratorの直前(5の前)に移動
    // print_list(il0); // 0,1,2,5,6
    print_list(il0); // 0,1,2,5,6
    print_list(il1); // 4,6
    print_list(il2); // 要素なし

    return 0;
}
