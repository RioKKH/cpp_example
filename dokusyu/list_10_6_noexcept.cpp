#include <iostream>

// この関数から例外が飛んでくることはない
void no_throw_exception() noexcept
{
    try
    {
        throw 0; // 内部ではthrowをすることができる！
    }
    catch (...)
    {
        //- noexcept を指定した関数でも、内部でちゃんと捕まえていれば問題ない
        std::cout << "関数内部で例外を捕まえました" << std::endl;
    }

    //- noexceptが指定されているので、関数の外部に例外を投げることはできない!
    //- この関数が外部に例外を投げると、std::terminate()関数が呼ばれて異常終了する
    // throw 1;
}

int main()
{
    // この関数から例外が飛んでくることはない
    try
    {
        no_throw_exception();
    }
    catch (int e)
    {
        std::cout << "catched." << std::endl;
    }
}
