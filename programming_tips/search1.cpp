#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // true
    // v1の中に{4, 5, 6}という並びが存在するので、これはtrueになる
    std::vector<int> v2 = {4, 5, 6};
    bool a = std::search(std::begin(v1), std::end(v1), std::begin(v2), std::end(v2));

    // false
    // v1の中に{1, 3, 5}という並びが存在しないので、これはfalseになる
    std::vector<int> v3 = {1, 3, 5};
    bool b = std::search(std::begin(v1), std::end(v1), std::begin(v3), std::end(v3));
}
