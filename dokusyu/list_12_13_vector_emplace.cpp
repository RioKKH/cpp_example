#include <iostream>
#include <vector>
#include <string>

void print_vector(const std::vector<int>& v)
{
    for (int i : v)
    {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
}

/*
 * empace()
 * 引数の数が可変となっている
 * template <typename... T>
 * iterator emplace(const_iterator pos, T&&... args);
 * 第二引数以降の要素をコンストラクター引数として用い、
 * コピーを作らずにコンテナ内に直接生成する
 */

class person
{
private:
    std::string name;
    int age;

public:
    explicit person(const char* n, int a) : name{n}, age{a}
    {
    }

    void show() const
    {
        std::cout << "name: " << name << ", age: " << age << std::endl;
    }
};

int main()
{
    std::vector<person> pv;
    // "alice", 12でpersonをコンテナ内に生成する
    // コピーを作らずにコンテナ内に直接生成しているところがinsert()との違い
    pv.emplace(pv.end(), "alice", 12);
    
    for (const auto& p : pv)
    {
        p.show();
    }

    return 0;
}

