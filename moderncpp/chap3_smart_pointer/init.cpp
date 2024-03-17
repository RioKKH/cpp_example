#include <iostream>
#include <memory> // スマートポインタの利用に必要
#include <tuple> // タプルの利用に必要
using namespace std;

int main() {
    // デフォルトコンストラクタで初期化 (nullptrが入る)
    unique_ptr<int> u_int_ptr;       // int型のunique_ptr
    shared_ptr<string> s_str_ptr;    // string型のshared_ptr

    cout << "# declare with default value (nullptr)" << endl;
    cout << u_int_ptr.get() << endl;
    cout << s_str_ptr << endl;

    // C++11 初期値を与えてスマートポインタを宣言する
    // コンストラクタに引数を与えて初期化する (初期値が入る)
    unique_ptr<int> u_int_ptr2(new int(100)); // int型のunique_ptr
    shared_ptr<string> s_str_ptr2(new string("Hello")); // string型のshared_ptr

    cout << "# declare with initial value" << endl;
    cout << u_int_ptr2.get() << "," << *u_int_ptr2 << endl;
    cout << s_str_ptr2 << "," << *s_str_ptr2 << endl;

    // C++11 reset関数によるメモリ領域の割り当て
    // インスタンスだけを作成しておき、後からメモリ領域を割り当てる
    // 所有権の委譲が行われる
    u_int_ptr.reset(new int(200));
    s_str_ptr.reset(new string("World"));

    cout << "# reset" << endl;
    cout << u_int_ptr.get() << "," << *u_int_ptr << endl;
    cout << s_str_ptr       << "," << *s_str_ptr << endl;

    // C++11/C++14 make_unique<T>/make_shared<T>関数による初期化
    // インスタンス生成とメモリ領域の割り当てを一度に行う
    // 型推論が働くので宣言文が簡潔になる
    // このmake_uniqueとmake_sharedを使うことを推奨
    auto u_int_ptr3 = make_unique<int>(200); // C++14から
    auto s_str_ptr3 = make_shared<string>("Hello, World!");
    
    cout << "# make_unique, make_shared" << endl;
    cout << u_int_ptr3.get() << "," << *u_int_ptr3 << endl;
    cout << s_str_ptr3       << "," << *s_str_ptr3 << endl;

    // make_unique<T>関数, make_shared<T>関数は、Tのコンストラクタが複数の値を
    // 受け取る場合にも利用できる
    // 複数の引数を持つコンストラクタを呼び出す
    auto u_tuple_ptr = make_unique<tuple<int, int, string>>(200, 10, "Hello"); // 
    auto s_tuple_ptr = make_shared<tuple<int, int, string>>(1000, 20, "World");

    cout << "# make_unique, make_shared with tuple" << endl;
    cout << get<0>(*u_tuple_ptr) << "," << get<1>(*u_tuple_ptr)
        << "," << get<2>(*u_tuple_ptr) << endl;
    cout << get<0>(*s_tuple_ptr) << "," << get<1>(*s_tuple_ptr)
        << "," << get<2>(*s_tuple_ptr) << endl;

#if FALSE
    // 初期化されないので明示的に値を設定する必要がある
    // このような使い方は推奨されない
    // make_unique_for_overwrite<T>関数、make_shared_for_overwrite<T>関数
    // は利用に慎重になるべき
    auto u_str_ptr4 = make_unique_for_overwrite<string>();
    auto s = *ustr_ptr4; // 値は不定となる。
    *u_str_ptr4 = "OK"; // 明示的に値を上書きする=OK
#endif

    return 0;
}



