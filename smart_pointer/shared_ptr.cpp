#include <iostream>
#include <memory>

int main()
{
    //あるメモリの所有権を、複数のshared_ptr<T>で共有することが出来る。
    //メモりの解放は全てｎ所有権を持つshared_ptr<T>が破棄された際に実行される
    //コピーもムーブも可能
    //内部でカウンタを利用している関係上、やや通常のポインタよりメモリ確保や
    //コピーというの処理が遅い。
    //配列を扱うことが出来る。但し、明示的にdeleterを指定する必要がある。
    
    //空のshared_ptrを作成
    std::shared_ptr<int> ptr;

    {
        // intの所有権を持つptr2を作成
        std::shared_ptr<int> ptr2(new int(0));

        // ptr2の所有権をptrにコピー、共有する
        ptr = ptr2;

        *ptr += 10;
        std::cout << "ptr " << *ptr << std::endl;
        std::cout << "ptr2 " << *ptr2 << std::endl;

        *ptr2 += 10;
        std::cout << "ptr " << *ptr << std::endl;
        std::cout << "ptr2 " << *ptr2 << std::endl;
    } // ここでptr2のデストラクタが呼ばれる
      // ptrも同一のメモリに対する所有権を持っているため、まだ解放はされない

      // 当然ptrはまだ使用可能
    std::cout << "ptr = " << *ptr << std::endl;
}
// ここでptrのデストラクタが呼ばれる
// メモリの所有権を持つポインタがいなくなったので解放される
