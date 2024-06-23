#include <iostream>

// arrayクラスにイテレータを実装するためのクラス
template <typename Array>
struct array_iterator
{
    //- メンバデータ -----------------------------------------
    Array &a;
    std::size_t i;

    //- コンストラクター -------------------------------------
    array_iterator(Array &a, std::size_t i) : a(a), i(i) {}

    //- メンバ関数 -------------------------------------------
    // 次の要素を指す
    array_iterator &operator ++()
    {
        ++i;
        return *this;
    }

    // 前の要素を指す
    array_iterator &operator --()
    {
        --i;
        return *this;
    }

    // 今参照している要素へのリファレンスを返す
    typename Array::reference operator *()
    {
        return a[i];
    }
};


template <typename T, std::size_t N>
struct array
{
    //- エイリアス -------------------------------------------
    using reference = T &;
    using const_reference = T const &;

    using iterator = array_iterator<array>;

    //- メンバデータ -----------------------------------------
    T storage[N];

    //- メンバ関数 -------------------------------------------
    // 非const版
    reference operator [](std::size_t i)
    {
        return storage[i];
    }

    // const版
    const_reference operator [](std::size_t i) const
    {
        return storage[i];
    }

    // 先頭要素のイテレーター
    iterator begin()
    {
        return iterator(*this, 0);
    }

    // 最後の次の要素へのイテレータ
    iterator end()
    {
        return iterator(*this, N);
    }
};


int main()
{
    array<int, 5> a = {1, 2, 3, 4, 5};

    auto iter = a.begin();
    std::cout << *iter << std::endl;
    ++iter;
    std::cout << *iter << std::endl;
    std::cout << a[2] << std::endl;

    std::cout << ++i << std::endl;
}

