#include <iostream>
#include <string>

int main()
{
    auto lambda = [](const auto& value)
    {
        std::cout << value << std::endl;
    };

    lambda(1);
    lambda(1.0f);
    lambda("abc");
}
