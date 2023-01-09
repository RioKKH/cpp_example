#include <iostream>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& pv)
{
    std::cout << "v.size(): " << pv.size() << std::endl;

    if (! pv.empty())
    {
        for (const auto& p : pv)
        {
            p.show();
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "There is nothing to print out." << std::endl;
    }
}

class person
{
private:
    std::string name;
    std::int32_t age;

public:
    explicit person(const char* n, int a) : name{n}, age{a}
    {
    }

    void show() const
    {
        std::cout << "name: " << this->name << ", age: " << this->age << std::endl;
    }
};


int main()
{
    std::vector<person> pv;
    pv.push_back(person{"alice", 20});
    pv.emplace_back("bob", 18); // personコンストラクターが呼ばれる

    print_vector(pv);

    return 0;
}
