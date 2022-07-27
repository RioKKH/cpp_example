#include <algorithm>
#include <iostream>
#include <vector>

class Counter {
private:
    int index = 0;
    int m_n;
    int m_r;
    std::vector<bool> v;

public:
    Counter() : m_n(0), m_r(0)
    {
    }

    Counter(int n, int r) : m_n(n), m_r(r)
    {
        v.resize(m_n);
        std::fill(v.begin(), v.begin() + r, true);
    }

    int operator()()
    {
        if (std::next_permutation(v.begin(), v.end()))
        {
            for (int i = index; i < m_n; ++i)
            {
                if (v[i])
                {
                    std::cout << (i + 1) << " ";
                }
            }
            std::cout << std::endl;
        }
        return 0;
    }
};

int main()
{
    std::vector<int> v(10);

    for (const auto& a : v)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    int n = 1;
    std::generate(v.begin(), v.end(), [&n]() { auto t = n; n *= 2; return t;});
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << ",";});

    std::generate(v.begin(), v.end(), Counter());
    for (const auto a : v)
    {
        std::cout << a << std::endl;
    }

    return 0;
}
