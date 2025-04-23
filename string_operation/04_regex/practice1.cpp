#include <iostream>
#include <string>
#include <vector>
#include <regex>

// 文字列全体がメールアドレスかどうか判定する関数
bool is_email(const std::string &s)
{
    // ^...$で全文一致をチェック、icaseで大文字小文字を無視する
    static const std::regex re(
        R"(^[A-Za-z0-9._%+/-]+@[A-Za-z0-9.\-]+\.[A-Za-z]{2,}$)",
        std::regex::ECMAScript | std::regex::icase);
    return std::regex_match(s, re);
}

// テキスト中からメールアドレスを全て抽出関数
std::vector<std::string> extract_emails(const std::string &text)
{
    // 部分一致用。全文一致用とは少しパターンを緩める（末尾の$は外す）
    static const std::regex re(
        R"(([A-Za-z0-9._%+/-]+)@([A-Za-z0-9.\-]+\.[A-Za-z]{2,}))",
        std::regex::ECMAScript | std::regex::icase);
    std::vector<std::string> emails;
    // regex_iteratorを使うと文字列コピーを避けてシンプルに書ける
    auto begin = std::sregex_iterator(text.begin(), text.end(), re);
    auto end = std::sregex_iterator();
    for (auto it = begin; it != end; ++it)
    {
        emails.push_back(it->str());
    }
    return emails;
}

int main()
{
    const std::string doc = R"(
        ご連絡先:
        alice@example.com
        BOB.SMITH@Sub.Domain.Co.JP
        foo@local
        user+tag@my-site.org
        invalid@.com
    )";

    // is_emailテスト
    std::cout << std::boolalpha;
    std::cout << "alice@example.comの判定：" << is_email("alice@example.com") << "\n";
    std::cout << "invalid@.comの判定：" << is_email("invalid@.com") << "\n\n";

    // extract_emailsテスト
    auto list = extract_emails(doc);
    std::cout << "抽出結果:\n";
    for (auto &e : list)
    {
        std::cout << " " << e << std::endl;
    }
    return 0;
}
