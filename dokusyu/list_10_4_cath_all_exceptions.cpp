#include <iostream>

void throw_zero()
{
    throw 0; // int型の例外オブジェクトを投げる
}

int main()
{
    try
    {
        throw_zero();
    }
    catch (float f)
    {
        std::cout << "float型の例外オブジェクトを捕まえました " << f << std::endl;
    }
    catch (...) // どのcatch節にも一致しなかった場合、すべての例外を捕まえることができる
    {
        // ただし、例外オブジェクトの値を取得することはできない
        std::cout << "未対応の例外オブジェクトをつかまえました" << std::endl;
    }
    // catch(...) の後ろには他のcatch節をおくことはできない

    std::cout << "after catch clause" << std::endl;
}

