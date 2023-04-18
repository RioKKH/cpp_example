#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4};
    // コンテナ内の全要素に対し、偶数なら2で割る
    // コンテナ内の各要素はイテレータを使ってアクセス可能
    // 要素の値はポインターと同様に関節参照演算子を使って取得できる
    for (auto iter = v.begin(); iter != v.end(); ++iter)
    {
        // iteratorに関節参照演算子を使って要素にアクセス
        if (*iter % 2 == 0)
        {
            *iter /= 2;
        }
    }

    for (int i : v)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
