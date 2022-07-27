#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> A(10);
    for (const auto& a : A) { std::cout << a << " "; }; std::cout << std::endl;

    for_each(A.begin(), A.end(), [](int& n) { n = 1; });
    for (const auto& a : A) { std::cout << a << " "; }; std::cout << std::endl;

    A.clear();
    for (const auto& a : A) { std::cout << a << " "; }; std::cout << std::endl;

    return 0;
}
