#include <iostream>

void expanded(int a)
{
    std::cout << "{" << a << "}" << std::endl;
}

void expanded(int a, int b)
{
    std::cout << "{" << a << ", " << b << "}" << std::endl;
}

void expanded(int a, int b, int c)
{ std::cout << "{" << a << ", " << b << ", " << c << "}" << std::endl;
}

template <typename... T>
void expanding(T... args)
{
    int n = sizeof...(args);
    if (n == 0)
    {
        std::cout << "no argument" << std::endl;
    }
    else if (n > 3)
    {
        std::cout << "Too much argument" << std::endl;
    }
    else
    {
        // NG このコードは動かない。原因が分かっていない
        expanded(args...);
        // expanded(args...);
    }
}

int main()
{
    expanding(1);
    expanding(1, 2);
    expanding(1, 2, 3);
    expanding(1, 2, 3, 4);

    return 0;
}

