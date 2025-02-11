#include <iostream>

auto print = [](auto value){ std::cout << value << std::endl; };

int absolute(int value)
{
    int abs;

    if (value < 0)
    {
        abs = -value;
    }
    else
    {
        abs = value;
    }
    return abs;
}

// ternary_conditional_operatorを使う事で下のようにシンプルに書ける。
// 複雑な処理を3項条件演算子に実行させるべきではないが、上のような簡単
// な処理で行数が地味にかかる場合には便利
int absolute_ternary(int value)
{
    int abs = value < 0 ? -value : value;
    return abs;
}

int main()
{
    int a = absolute(-2);
    int b = absolute_ternary(-2);
    print(a);
    print(b);
}
