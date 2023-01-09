#include <iostream>
#include <vector>

/*
 * erase()
 * 1つ目のオーバーロードではイテレータで指定された要素のみを削除する
 * iterator erase(const_iterator pos);
 * 2つ目のオーバーロードではイテレータで指定された範囲の全要素を削除する
 * iterator erase(const_iterator first, const_iterator last);
 * どちらの場合も削除した要素の次の要素へのイテレータが返される
 */

template <typename T>
void print_vector(const std::vector<T>& v)
{
    for (T i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4};
    print_vector(v);

    auto it = v.begin() + 1; // 先頭から2番目を指す
    v.erase(it);
    print_vector(v);

    return 0;
}
