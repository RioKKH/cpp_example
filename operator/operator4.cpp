#include <iostream>

struct IntLike{ int data; };

IntLike operator + (IntLike const &l, IntLike const &r)
{
    return IntLike{ l.data + r.data };
}

int main()
{
    IntLike a{1};
    IntLike b{1};

    auto c = a + b;
    std::cout << c.data << std::endl;
}

