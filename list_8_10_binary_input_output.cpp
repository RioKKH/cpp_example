#include <iostream>
#include <fstream>

int main()
{
    std::ofstream out{"hello_binary.bin", std::ios::binary};

    // 人間が文字として認識出来ない数値を直接出力
    out.put(1);

    // ストリームがかえされるのでこのように連続して呼ぶことが出来る
    out.put(2).put(3);

    out.close();

    char a, b, c;
    std::ifstream in{"hello_binary.bin", std::ios::binary};

    // 1バイトを直接入力
    in.get(a);
    in.get(b).get(c); // get()関数も同様に連続して呼べる。
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
}
