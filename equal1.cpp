#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> a = {1, 2, 3, 4, 5};
    // aと等しい
    std::vector<int> b = {1, 2, 3, 4, 5};
    // aと等しくない
    std::vector<int> c = {1, 2, 3, 4, 5, 6};
    // aと等しくない
    std::vector<int> d = {1, 2, 2, 4, 6};

    // true -> 1
    bool ab = std::equal(std::begin(a), std::end(a), std::begin(b), std::end(b)); 
    // false -> 0
    bool ac = std::equal(std::begin(a), std::end(a), std::begin(c), std::end(c)); 
    // false -> 0
    bool ad = std::equal(std::begin(a), std::end(a), std::begin(d), std::end(d)); 

    std::cout << ab << ", " << ac << ", " << ad << std::endl;
}
