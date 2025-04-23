#include <iostream>
#include <string>

int main()
{
    std::string text = "The quick brown fox jumps over the lazy dog.";

    // find
    auto p1 = text.find("fox");
    // rfind
    auto p2 = text.rfind("the"); // the lazy
    // find_first_of : 母音を探す
    auto p3 = text.find_first_of("aeiou");
    // find_last_of : 最後の母音を探す
    auto p4 = text.find_last_of("aeiou");
    // find_first_not_of : 空白以外の最初
    auto p5 = text.find_first_not_of(" ");
    // find_last_not_of : 終端以外の最後
    auto p6 = text.find_last_not_of(" .");

    std::cout
        << "fox at " << p1 << std::endl
        << "last 'the' at " << p2 << std::endl
        << "first vowel at " << p3 << std::endl
        << "last vowel at " << p4 << std::endl
        << "first non-space at " << p5 << std::endl
        << "last non-space/dot at " << p6 << std::endl;
}
