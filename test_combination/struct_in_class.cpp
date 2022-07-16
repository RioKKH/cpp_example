#include <iostream>
#include <vector>

typedef struct {
    std::vector<int> x;
    std::vector<int> y;
} POS_s;

class A
{
private:
    POS_s raw;
    POS_s tri;

public:
    A();
    ~A();
    void setA();
    void copy();
    void show_raw();
    void show_tri();
};

A::A()
{
}

A::~A()
{
}

void A::setA()
{
    for (int i = 0; i < 10; ++i)
    {
        raw.x.emplace_back(i);
        raw.y.emplace_back(i*2);
    }
}

void A::copy()
{
    for (size_t i = 0; i < raw.x.size(); ++i)
    {
        if ((i > 2) && (i < 8))
        {
            tri.x.push_back(raw.x[i]);
            tri.y.push_back(raw.y[i]);
        }
    }
}

void A::show_raw()
{
    for (size_t i = 0; i < raw.x.size(); ++i)
    {
        std::cout << raw.x[i] << std::endl;
    }
}

void A::show_tri()
{
    for (size_t i = 0; i < tri.x.size(); ++i)
    {
        std::cout << tri.x[i] << std::endl;
    }
}

int main()
{
    A a;
    std::cout << "raw_pre" << std::endl;
    a.setA();
    a.show_raw();
    a.copy();
    std::cout << "raw_post" << std::endl;
    a.show_raw();
    std::cout << "tri_post" << std::endl;
    a.show_tri();
}

