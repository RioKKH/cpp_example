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
    // 1. ファイル名部分の先頭位置を探す
    size_t slash = filename.find_last_of("/\\");
    size_t name_pos = (slash == std::string::npos) ? 0 : slash + 1;

    // 2. ドットの最終位置を探す
    size_t dot = filename.find_last_of(".");

    // 3. エッジケース判定
    if (dot == std::string::npos)
    {
        return ""; // ドット無し
    }
    if (dot < name_pos + 1)
    {
        return ""; // 先頭ドットのみ or ディレクトリ部分のドット
    }
    if (dot == filename.length() - 1)
    {
        return ""; // 末尾ドット
    }

    // 4. ドット以降を返す
    return filename.substr(dot);
}

int main()
{
    // テスト用ファイル名リスト
    const std::string filenames[] = {
        "report.pdf",     // .pdf
        "archive.tar.gz", // .gz
        "Makefile",       // ""
        ".bashrc",        // .bashrc
        "no_ext.",        // 空文字
        "/usr/local/bin/tool.sh",
        ".bashrc",
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
