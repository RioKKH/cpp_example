#include <iostream>

struct S
{
    int data{};
    // *thisはメンバー関数を呼んだクラスのオブジェクトへのリファレンスである
    S & THIS(){ return *this; }
    // thisはメンバー関数を呼んだクラスのオブジェクトへのポインターである
    S *pTHIS(){ return  this; }
};


int main()
{
    // 上の説明文だとややこしいが、下の実例を見るとわかりやすい。
    S s1;
    s1.THIS().data = 123; // thisはSのオブジェクトのs1を指している
    std::cout << s1.data << std::endl; // 123

    S s2;
    s2.THIS().data = 456; // thisはSのオブジェクトのs2を指している
    std::cout << s2.data << std::endl; // 456

    S s3;
    s3.pTHIS()->data = 789;
    std::cout << s3.data << std::endl; // 789
}
