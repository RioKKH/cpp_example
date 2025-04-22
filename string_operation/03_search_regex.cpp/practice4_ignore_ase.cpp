#include <iostream>
#include <string>
#include <regex>

// case-insensitive
void replace_case_insensitive(std::string &text,
                              const std::string &old_word,
                              const std::string &new_word)
{
    if (old_word.empty())
        return;
    // std::regexで特殊文字をエスケープしたい場合はさらに処理が必要
    std::regex re(old_word, std::regex_constants::ECMAScript | std::regex_constants::icase);
    text = std::regex_replace(text, re, new_word);
}

int main()
{
    std::string s = "Foo foo FOO Foobar";
    replace_case_insensitive(s, "foo", "x");
    std::cout << s << std::endl;
}
