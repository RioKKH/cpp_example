#include <iostream>
#include <utility>
#include <set>

int main()
{
    std::set<std::pair<int, int>> s;

    s.emplace(3,2);
    s.emplace(17,2);
    // s.emplace(3,2);
    // s.emplace(17.2);

    for (const auto& a : s)
    {
        std::cout << a.first << " " << a.second << std::endl;
    }
}


