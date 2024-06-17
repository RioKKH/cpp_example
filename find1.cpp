#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    // 3を指すイテレータ
    auto pos = std::find(std::begin(v), std::end(v), 3);

    std::cout << *pos; // 3が出力される
}
