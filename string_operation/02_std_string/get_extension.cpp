#include <iostream>
#include <string>

/**
 * 演習2: ファイル名から拡張子を抜き出す関数
 * 例: "report.pdf"     -> ".pdf"
 *     "archive.tar.gz" -> ".gz"
 *     "Makefile"       -> ""
 */
std::string get_extension(const std::string &filename)
{
    // 末尾からドットを探す
    size_t pos = filename.rfind('.');
    std::cout << "posision of most right dot : " << pos << std::endl;
    // ドットが見つからない、または末尾にある場合は拡張子無し
    // std::string::npos --> 空文字
    if (pos == std::string::npos || pos == filename.length() - 1)
    {
        return "";
    }
    // ドット以降を返す
    return filename.substr(pos);
}

int main()
{
    // テスト用ファイル名リスト
    const std::string filenames[] = {
        "report.pdf",     // .pdf
        "archive.tar.gz", // .gz
        "Makefile",       // ""
        ".bashrc",        // .bashrc
        "no_ext."         // 空文字
    };
    for (const auto &f : filenames)
    {
        std::cout
            << f
            << " -> \""
            << get_extension(f)
            << "\""
            << std::endl;
    }
    return 0;
}
