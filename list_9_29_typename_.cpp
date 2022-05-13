#include <iostream>
#include <vector>

// テンプレートパラメータのメンバ型ではない型に対するtypename
// テンプレートパラメータの型に、ネストされた型をしているする時
template <typename T>
typename std::vector<T>::reference // Tをつかっているのでtypenameが必要
at(std::vector<T>& v, std::size_t i)
{
    return v[i]; // std::vector<T>::reference型を返す
}

template <typename T>
typename std::size_t // Tに依存していないので本来はtypename不要だがエラーはでない
size(const std::vector<T> &v)
{
    return v.size();
}

int main()
{
    std::vector<int> v = {0, 1, 2, 3};

    // std::vector自体はテンプレートだが、main()関数は関数テンプレートではなく、
    // テンプレートパラメータを使っているわけではないので、これは依存名ではない

    std::vector<int>::reference r = at(v, 0);
    std::cout << r << std::endl;

    return 0;
}
