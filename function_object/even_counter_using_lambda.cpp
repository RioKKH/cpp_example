#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int evenCount = 0;
    // 1. ラムダ式の内部表現：
    //   コンパイラはラムダ式を見つけると、内部的に一意の名前を持つ
    //   クラスを生成し、そのクラスのoperator()を定義する。このクラスは
    //   関数オブジェクトとして機能する。
    // 2. for_eachへの適用:
    //   std::for_eachに渡されるラムダ式は、この内部的に生成された
    //   関数オブジェクトのインスタンスとして扱われる
    std::for_each(numbers.begin(), numbers.end(),
            [&evenCount](int x){ if (x % 2 == 0) { ++evenCount; }
    });

    std::cout << "Number of even numbers: " << evenCount << std::endl;
    return 0;
}
