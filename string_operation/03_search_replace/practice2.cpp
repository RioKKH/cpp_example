#include <iostream>
#include <string>

void replace_all(std::string &text,
                 const std::string &old_word,
                 const std::string &new_word)
{
    size_t pos = 0;

    // old_wordが空文字列の場合は何もしない
    if (old_word.empty())
        return;

    // ガードを入れる
    while ((pos = text.find(old_word, pos)) != std::string::npos)
    {
        text.replace(pos, old_word.size(), new_word);
        // 検索開始位置をずらす
        pos += new_word.size();
    }
}

int main()
{
    std::string s = "foo bar foofoo baz";
    replace_all(s, "foo", "x");
    std::cout << "After: " << s << std::endl;

    // 無限ループしない事を確認するためのテスト
    s = "foo bar foofoo baz";
    replace_all(s, "o", "oo");
    std::cout << "After: " << s << std::endl;

    return 0;
}
