#include <cstdint>
#include <iostream>
#include <utility> // std::pair<T, U>を用いるため

int main()
{
    // std::pair<T, U>は2つの値しか格納できないが、
    // 標準ライブラリの様々な場所で使われている基本的な型である
    std::pair<std::string, std::int32_t> si{"pair", 42};

    std::cout << si.first << ", " << si.second << std::endl;

    return 0;
}
