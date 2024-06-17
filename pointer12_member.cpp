#include <iostream>

struct Object
{
    int data_member;
    void member_function()
    {
        std::cout << data_member << std::endl;
    }
};

// メンバーへのポインター
// 目的: クラスのオブジェクトからは独立したデータメンバーや
// メンバー関数自体へのポインターを取得する
int main()
{
    // Object::data_memberメンバーへのポインター
    int Object::* int_ptr = &Object::data_member;

    // Object::member_functionメンバーへのポインター
    void (Object::* func_ptr)() = &Object::member_function;

    // クラスのオブジェクト
    Object object;

    // objectに対するメンバーポインターを介した参照
    object.*int_ptr = 123;

    // objectに対するメンバーポインターを介した参照
    (object.*func_ptr)(); // 123

    // 別のオブジェクト
    Object another_object;
    another_object.data_member = 456;
    (another_object.*func_ptr)();
}

