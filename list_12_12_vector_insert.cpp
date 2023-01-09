#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& v)
{
    for (int i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/*
 * insert()を使った挿入
 * iterator insert(const_iterator pos, const T& value);
 * 第1引数で指定されたイテレータの場所に挿入され、もともとそのイテレータが
 * 指していた先にあった要素は挿入された要素の次となる
 */

int main()
{
    std::vector<int> v = {1, 5, 9};
    print_vector(v);

    v.insert(v.begin(), 0); // 先頭に0を挿入
    print_vector(v);

    v.insert(v.end(), 10); // 末尾に10を挿入
    print_vector(v);

    v.insert(v.begin() + 2, 2, 3); // 先頭から2番目(5)の手前に2個の3を挿入する
    print_vector(v);

    int ia[] = {6, 7, 8};
    // 末尾から2つ前(9)の手前にiaを挿入する
    // ia + 3なので、6, 7, 8の3つを挿入することになる
    v.insert(v.end() - 2, ia, ia + 3); // イテレータが指す範囲を挿入
    print_vector(v);

    return 0;
}
