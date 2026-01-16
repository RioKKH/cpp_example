#include <iostream>

long long nCr2(long long n)
{
    return n * (n - 1) / 2;
}

long long nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    if (r > n / 2)
        r = n - r; // nCr = nCn-rを利用して計算量を減らす

    long long res = 1;
    for (int i = 1; i <= r; ++i)
    {
        res = res * (n - i + 1) / i;
    }
    return 0;
}

int main()
{
    int N;
    int num;
    long long odd = 0, even = 0, answer = 0;
    std::cin >> N;

    for (int i = 1; i <= N; i++)
    {
        std::cin >> num;
        if (num % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    answer += nCr2(even);
    answer += nCr2(odd);

    std::cout << answer << std::endl;
    return 0;
}
