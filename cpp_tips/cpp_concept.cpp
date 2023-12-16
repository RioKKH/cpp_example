#include <iostream>

/**
 * conceptキーワードは、テンプレートの型パラメータに制約を付けるために使用する
 * ことができる。制約とは、テンプレートの型パラメータが満たすべき条件のことである。
 * 例えば、テンプレートの型パラメータがint型であることを制約する場合は、
 * conceptキーワードを使用することで、int型以外の型を指定した場合にコンパイル
 * エラーとなるようにすることができる。
 * また、conceptキーワードを使用することで、テンプレートの型パラメータが持つ
 * メンバ関数やメンバ変数の有無をチェックすることもできる。
 * このように、conceptキーワードを使用することで、テンプレートの型パラメータに
 * 付ける制約を明示的に指定することができるようになる。
 * なお、conceptキーワードはC++20で導入された機能である。
 * このため、C++20以前のコンパイラでは、conceptキーワードを使用することはできない。
 * ただし、C++20以前のコンパイラでも、conceptキーワードを使用することはできないが、
 * conceptキーワードを使用したコードをコンパイルすることはできる。
 * この場合、conceptキーワードは無視される。
 */

// Printable concpet:
// ここではPrintableというconceptを定義している。
// これは、渡された型TがmemberPrintメソッドを持っているかどうかを
// 確認する。
// T型がmemberPrint()メソッドを持っている事をチェックする
template<typename T>
concept Printable = requires(T t) {
    // t.memberPrint()がコンパイルできることをチェックする
    // std::convertible_to<void>は、t.memberPrint()がvoid型に変換可能であることを
    // チェックする。つまり、t.memberPrint()がvoid型を返すことをチェックしている
    { t.memberPrint() } -> std::convertible_to<void>;
};

// Printable concpetを満たすクラス
class MyClass {
public:
    void memberPrint() const {
        std::cout << "MyClass instance" << std::endl;
    }
};

// Printable concpetを満たさないクラス
class NonPrintableClass {};

// Printable concpetを使用する関数テンプレート
template<Printable T>
void print(const T& obj) {
    obj.memberPrint();
}


int main()
{
    MyClass myObj;
    print(myObj); // OK: MyClassはPrintable conceptを満たす

    // NonPrintableClass nonPrintableObj;
    // コンパイルエラー:  NonPrintableClassはPrintable conceptを満たさない
    // print(nonPrintableObj);
}





