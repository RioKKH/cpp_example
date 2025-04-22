#include <iostream>
#include <string>

void replace_all(std::string &text,
                 const std::string &old_word,
                 const std::string &new_word)
{
    while (true)
    {
        auto p1 = text.find(old_word);
        if (p1 == std::string::npos)
        {
            break;
        }
        else
        {
            text.replace(p1, old_word.length(), new_word);
        }
    }
}

int main()
{
    std::string s = "foo bar foofoo baz";
    replace_all(s, "foo", "x");
    std::cout << "After: " << s << std::endl;
    return 0;
}
