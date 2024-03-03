#include <iostream>
#include <ostream>
#include <string>
#include <tuple> // std::tie
                 //
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& pair)
{
    return s << pair.first << ":" << pair.second;
}

int main()
{
    // pair構造体テンプレート
    std::pair<std::string, int> pair1{"黒柳徹子", 90};

    /**
     * 上記の記述で以下のような構造体が用意される
     * メンバ名がfirst, secondで固定される事に注意
     * struct pair {
     *   std::string first;
     *   int second;
     * } pair1 {"黒柳徹子", 90};
     */

    {
        // メンバ first, second
        std::cout << pair1.first << ":" << pair1.second << std::endl;
    }
    {
        // <<のオーバーロードで可能になるpairお表示
        std::cout << pair1 << std::endl;
    }
    {
        // std::tieで紐づける
        std::string name;
        int age;
        std::tie(name, age) = pair1;
        std::cout << name << ":" << age << std::endl;
    }
    /**
    {
        // C++17以降の構造化高速
        auto [name, age] = pair1;
        std::cout << name << ":" << age << std::endl;
    }
    */
    return 0;
}


