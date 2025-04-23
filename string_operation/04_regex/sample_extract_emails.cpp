#include <iostream>
#include <string>
#include <regex>
#include <vector>

// テキスト中のメールアドレスを全て抽出する
std::vector<std::string> extract_emails(const std::string &text)
{
    // 簡易的なメールアドレスパターン
    // R"(...)"で「生文字列リテラル」を使い、バックスラッシュエスケープを不要に
    static const std::regex re(
        R"(([A-Za-z0-9._%+-]+)@([A-Za-z0-9.-]+\.[A-Za-z]{2,}))",
        std::regex_constants::ECMAScript);

    std::smatch m;
    std::string s = text;
    std::vector<std::string> emails;

    // 部分一致検索を繰り返し
    while (std::regex_search(s, m, re))
    {
        emails.push_back(m.str(0)); // マッチした全文を追加
        // m.suffix(): マッチ以降の文字列抽出
        s = m.suffix().str(); // 残りのテキストで再検索
    }
    return emails;
}

int main()
{
    std::string doc = R"(
        連絡先:
        alice@example.com
        bob.smith@sub.domain.co.jp
        問い合わせは info@company.orgまで
    )";

    auto list = extract_emails(doc);
    for (auto &e : list)
    {
        std::cout << e << std::endl;
    }
}
