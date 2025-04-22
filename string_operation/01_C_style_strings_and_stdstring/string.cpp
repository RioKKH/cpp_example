#include <iostream>
#include <string>

int main()
{
    std::string a = "Hello";
    std::string b = "World";
    std::string c = a + ", " + b + "!";
    std::cout << " (length=" << c.length() << ")" << std::endl;

    return 0;
}
