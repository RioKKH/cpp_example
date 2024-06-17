#include <iostream>
#include <array>

// 実際には以下の記述は使われていないが、どのようにstd::arrayが実装されて
// いるのかを示す例として記述されている。
// ネストされた型名を使うことで、分かりづらいテンプレート引数を直接使うことを
// 回避することが出来ている
template <typename T, std::size_t N>
struct array
{
    using value_type = T;
    using reference = T &;
    using size_type = std::size_t;

    value_type storage[N];

    reference operator [](size_type i)
    {
        return storage[i];
    }
};

int main()
{
    using array_type = std::array<int, 5>;
    array_type a = {1, 2, 3, 4, 5};
    array_type::value_type x = 0;
    array_type::reference ref = a[0];
}
