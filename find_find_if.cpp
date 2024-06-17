#include <algorithm>

auto find = [](auto first, auto last, auto value)
{
    return std::find_if(first, last, [&](auto elem) { return value == elem; });
};
