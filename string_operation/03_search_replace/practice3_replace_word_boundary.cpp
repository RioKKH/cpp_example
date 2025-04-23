#include <iostream>
#include <string>
#include <cctype>

// ワード文字かどうか
bool is_word_char(char c)
{
    return std::isalnum(static_cast<unsigned char>(c)) || c == '_';
}

// ワード境界だけを置換する
void replace_word_boundary(std::string &text,
                           const std::string &old_word,
                           const std::string &new_word)
{
    if (old_word.empty())
        return;

    size_t pos = 0;
    while ((pos = text.find(old_word, pos)) != std::string::npos)
    {
        bool at_left = (pos == 0) || !is_word_char(text[pos - 1]);
        bool at_right = (pos + old_word.size() >= text.size()) || !is_word_char(text[pos + old_word.size()]);
        if (at_left && at_right)
        {
            text.replace(pos, old_word.size(), new_word);
            pos += new_word.size();
        }
        else
        {
            pos += old_word.size(); // 境界でなければ先へ進める
        }
    }
}

int main()
{
    std::string s = "foo foo_bar foot foo!";
    replace_word_boundary(s, "foo", "x");
    std::cout << "After: " << s << std::endl;

    return 0;
}
