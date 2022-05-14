#include <iostream>

template <typename... T>
void show_length(T... args)
{
    std::cout << sizeof...(T) << std::endl;
}

int main()
{
    show_length(1);
    show_length(1, 2);
    show_length(1, 2, 3);
    show_length(1, 2, 3, 4);
    show_length(1, 2, 3, 4, 5);

    return 0;
}
