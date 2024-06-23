#include <iostream>
#include <algorithm>

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
    // これは前置インクリメント
    array_iterator &operator ++ ()
    {
        ++i;
        return *this;
    }

    // 後置インクリメント
    array_iterator operator ++ (int)
    {
        array_iterator copy = *this;
        // ++dataとするよりも実装済みの前置インクリメントを
        // 呼ぶほうがコードの重複を省ける
        ++*this;
        return copy;
    }

    // 前の要素を指す
    // 前置デクリメント演算子
    array_iterator &operator -- ()
    {
        --i;
        return *this;
    }

    // 後置デクリメント演算子
    array_iterator operator -- (int)
    {
        array_iterator copy = *this;
        --*this;
        return copy;
    }

    // イテレータn回実行
    // i += 3でイテレータiを3回進めることに相当する
    array_iterator &operator += (std::size_t n)
    {
        i += n;
        return *this;
    }

    // i -= 3でイテレータiを3回戻すことに相当する
    array_iterator &operator -= (std::size_t n)
    {
        i -= n;
        return *this;
    }

    // auto j = i + 3でイテレータiの値は変えずに、iを3回進めたjを生成する
    array_iterator operator + (std::size_t n) const
    {
        auto copy = *this;
        copy += n; // copyの方をn回分だけ進め
        return copy; // copyをリターンする
    }

    // auto j = i - 3でイテレータiの値は変えずに、iを3回戻したjを生成する
    array_iterator operator - (std::size_t n) const
    {
        auto copy = *this;
        copy -= n; // copyの方をn回分だけ戻す
        return copy; // copyをリターンする
    }

    bool operator == (array_iterator const &right)
    {
        return i == right.i;
    }

    bool operator != (array_iterator const &right)
    {
        return i != right.i;
    }

    // 今参照している要素へのリファレンスを返す
    typename Array::reference operator * ()
    {
        return a[i];
    }

    typename Array::reference operator [] (std::size_t n) const
    {
        return *(*this + n); // 上で operator +を定義したので、ここで用いることが出来る
        // *this : このイテレータのオブジェクト
    }


    // イテレータの大小比較
    // rightは変更しないのでconstとしている。データメンバのiも変更しないので、
    // bool operator < () const {}とconstになっている。
    bool operator < (array_iterator const &right) const
    {
        return i < right.i;
    }

    bool operator <= (array_iterator const &right) const
    {
        return i <= right.i;
    }

    bool operator > (array_iterator const &right) const
    {
        return i > right.i;
    }

    bool operator >= (array_iterator const &right) const
    {
        return i >= right.i;
    }
};


template <typename Array>
struct array_const_iterator
{
    Array const &a;
    std::size_t i;

    // コンストラクター
    array_const_iterator(Array const &a, std::size_t i) : a(a), i(i) {}

    // array_iteratorからの変換コンストラクター
    array_const_iterator(typename array_iterator<Array>::iterator const &iter)
        : a(iter.a), i(iter.i) {}

    //- ++
    array_const_iterator operator ++ ()
    {
        ++i;
        return *this;
    }

    typename Array::const_reference operator *() const
    {
        return a[i];
    }

    typename Array::const_reference operator [] (std::size_t i) const
    {
        return *(*this +i);
    }
};


template <typename T, std::size_t N>
struct array
{
    //- エイリアス -------------------------------------------
    using reference = T &;
    using const_reference = T const &;

    using iterator = array_iterator<array>;
    using const_iterator = array_const_iterator<array>;

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

    // const arrayのときにconst_iteratorを返す
    const_iterator begin() const
    {
        return const_iterator(*this, 0);
    }

    const_iterator end() const
    {
        return const_iterator(*this, N);
    }

    // 常にconst_iteratorを返す
    const_iterator cbegin() const
    {
        return const_iterator(*this, 0);
    }

    const_iterator cend() const
    {
        return const_iterator(*this, N);
    }
};


int main()
{
    using Array = array<int, 5>;
    Array a = {1, 2, 3, 4, 5};

    // iterator
    auto i = a.begin();

    // iteratorからconst_iteratorへの変換
    Array::const_iterator j = i;
} 
