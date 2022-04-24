#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> a(3);
    a[0] = 1, a[1] = 2, a[2] = 3;
    for (const auto& b : a)
    {
        std::cout << b << std::endl;
    }
}
