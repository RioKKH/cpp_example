#include <iostream>

class S
{
public:
    static int num; // staticメンバー変数の宣言
    // staticメンバー変数は特定のインスタンスと紐付かない、同クラス
    // のインスタンス間で共有されるメンバー変数のこと
};

int S::num = 123; // staticメンバー変数の定義と初期化

int main()
{
    std::cout << S::num << std::endl;
    S::num = 456;
    S s;

    // 特定のインスタンスを経由してもアクセス出来るが、実態は同じものを指している
    std::cout << s.num << std::endl;
}
