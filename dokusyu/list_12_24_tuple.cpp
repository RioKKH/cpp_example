#include <cstdint>
#include <iostream>
#include <tuple>

/*
 * template <std::size_t N, typename... T>
 * element-type& get(std::tuple<T...>& tuple);
 */

int main()
{
    std::tuple<std::int32_t, std::string, char> isc{42, "tuple", 'c'};

    std::cout << std::get<0>(isc) << std::endl;
    std::cout << std::get<1>(isc) << std::endl;
    std::cout << std::get<2>(isc) << std::endl;

    return 0;
}
