#include <iostream>
#include <string>

void substr(const std::string &filename)
{
    return;
}

int main()
{
    std::string A = "Mount";
    std::string B = "Fuji";
    std::string C = "";

    std::cout << A << ": using length() : " << A.length() << std::endl;
    std::cout << A << ": using size()   : " << A.size() << std::endl;
    std::cout << A + " " + B << std::endl;
    C = A;
    C += " ";
    C += B;
    std::cout << C << std::endl;

    if (A.compare(B))
    {
        std::cout << "A is not equal to B" << std::endl;
    }
    if (!A.compare(A))
    {
        std::cout << "A is equal to A" << std::endl;
    }
    // Mount
    std::cout << C.substr(0, 5) << std::endl;
}
