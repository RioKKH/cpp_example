#include <iostream>
#include <string>

int main()
{
    // replace(pos, len, new_str)
    //   pos: 置換開始位置
    //   len: 元文字列から何文字を消すか
    //   new_str: 挿入する文字列
    std::string s = "I love C++ and C++ is powerful.";
    std::cout << "Before: " << s << std::endl;
    // 最初の"C++" を "Python"に置換
    s.replace(s.find("C++"), 3, "Python");
    std::cout << "After:  " << s << std::endl;

    return 0;
}
