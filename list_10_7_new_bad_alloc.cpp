#include <new> // std::bad_alloc例外に必要
#include <iostream>

int main()
{
    try
    {
        /**
         * メモリ領域を確保できなかった場合、std::bad_alloc例外を投げる。
         * 配列のnew 演算子では、動的確保した配列の長さが初期化リストの
         * 長さより短い場合にstd::bad_array_new_length例外を投げる
         */
        int* ptr = new int;
        
        std::cout << "ptrを確保" << std::endl;

        delete ptr;
    }

    // メモリ割り当てが失敗した場合の例外ハンドラー
    catch (std::bad_alloc& e)
    {
        std::cout << "メモリ割り当てに失敗しました" << std::endl;
    }
}

