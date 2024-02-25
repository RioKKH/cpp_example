#include <iostream>

class printer
{
public:
    printer()
    {
        std::cout << "Hello World!" << std::endl;
    }

    // This is a const member function
    void print() const
    {
        std::cout << "Hello World!" << std::endl;
    }
};

int main()
{
    printer p[10];

    for (const auto& i : p)
    {
        i.print();
    }
}
