#include <iostream>
#include <memory>
using namespace std;

int main() {
    {
        auto u_int_ptr = make_unique<int>(100);
        auto s_str_ptr = make_shared<string>("hello");
        // デストラクタが呼ばれるときにメモリ領域が解放される。
        // ここでメモリ領域が解放される。
    }

    auto u_int_ptr = make_unique<int>(100);
    auto s_str_ptr = make_shared<string>("world");

    // 代入でそれまで所有していたメモリ領域が解放される。
    u_int_ptr = make_unique<int>(200);
    s_str_ptr = make_shared<string>("again");

    // reset関数でそれまでに所有していたメモリ領域が解放される
    u_int_ptr.reset(new int(300));
    s_str_ptr.reset(new string("reset"));

    {
        auto u_int_ptr = std::make_unique<int>(10);
        auto s_str_ptr = std::make_shared<string>("force");

        // reset関数を引数無で呼び出すことで明示的に解放出来る
        u_int_ptr.reset();
        s_str_ptr.reset();
    }
    return 0;
}




