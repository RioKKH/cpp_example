#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}


std::vector<std::string> split_naive(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    std::string item;
    for (char ch : s) {
        if (ch == delim) {
            if (!item.empty()) {
                elems.push_back(item);
            }
            item.clear();
        } else {
            item += ch;
        }
    }
    if  (!item.empty()) {
        elems.push_back(item);
    }
    return elems;
}


int main(int argc, char const* argv[])
{
    std::string str;
    int temp;
    std::vector<int> v;
    std::vector<std::string> vstr1, vstr2;

    getline(std::cin, str);
    std::stringstream ss(str);
    vstr1 = split(str, ' ');
    vstr2 = split_naive(str, ' ');

    for (const auto& x : vstr1) {
        std::cout << x << std::endl;
    }

    for (const auto& x : vstr2) {
        std::cout << x << std::endl;
    }

    return 0;
}
