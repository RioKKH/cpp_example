#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <ostream>

template <class T1, class T2>
std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& pair)
{
    return s << pair.first << " : " << pair.second;
}

template <class C>
void show(const C& data)
{
    for (const auto& d : data)
    {
        // 上で定義したoperator<<が呼ばれる
        std::cout << d << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    // pairのvector配列
    std::vector<std::pair<std::string, int>> vec;
    vec.emplace_back("AKB", 48);
    vec.emplace_back("NMB", 48);
    vec.emplace_back("HKT", 48);
    show(vec);

    // pairのlist
    std::list<std::pair<std::string, int>> list;
    list.emplace_back("乃木坂", 46);
    list.emplace_back("欅坂",   46);
    list.emplace_back("日向坂", 46);
    show(list);

    return 0;
}

