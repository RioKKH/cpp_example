#include <iostream>
#include <vector>

int main()
{
    std::vector<int> iv0 = {1, 2, 3, 4, 5}; // コピー元
    std::vector<int> iv1 = iv0; // コピー。値のコピーであって参照ではない

    for (const auto& i : iv1)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
