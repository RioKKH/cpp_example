#include <iostream>

struct fractional
{
    int num;    // 分子 numerator
    int denom;  // 分母 denominator
};

// 演算子のオーバーロード
fractional operator +(fractional &l, fractional &r)
{
    // 分母が同じなら
    if (l.denom == r.denom)
    {
        // 単に分子を足す
        return fractional{l.num + r.num, l.denom}; // {}内の数値で初期化してfractional構造体を返す

    } else {
        // 分母を合わせて足す
        return fractional{l.num * r.denom + r.num * l.denom, l.denom * r.denom};
    }
}

fractional operator -(fractional &l, fractional &r)
{
    // 分母が同じ
    if (l.denom == r.denom)
    {
        return fractional{l.num - r.num, l.denom};
    } else {
        return fractional{l.num * r.denom - r.num * l.denom, l.denom * r.denom};
    }
}

fractional operator *(fractional &l, fractional &r)
{
    return fractional{l.num * r.num, l.denom * r.denom};
}

fractional operator /(fractional &l, fractional &r)
{
    return fractional{l.num * r.denom, l.denom * r.num};
}


int main()
{
    fractional a{1, 2};
    fractional b{1, 3};

    auto c = a + b;
    auto d = a - b;
    auto e = a * b;
    auto f = a / b;

    std::cout << c.num << "/" << c.denom << std::endl;
    std::cout << d.num << "/" << d.denom << std::endl;
    std::cout << e.num << "/" << e.denom << std::endl;
    std::cout << f.num << "/" << f.denom << std::endl;
}

