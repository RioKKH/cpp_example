#include <iostream>
#include <string>

// 実際にテンプレートパラメ−タが何に推論されたかを確認する方法
// specializationを用いる方法

// ヘルパー関数の前方宣言
// これがprimary templateのはず
template <typename T>
class helper;

// intのときに使われるヘルパークラス
// 明示的特殊化 explicit specialization
template <>
class helper<int>
{
public:
    static std::string name() { return "int"; }
};

// doubleのときに使われるヘルパークラス
// 明示的特殊化 explicit specialization
template <>
class helper<double>
{
public:
    static std::string name() { return "double"; }
};

template <typename T>
struct A
{
    T value;
};

template <typename T>
void deduce(A<T> a)
{
    // 推論されたTを使ってヘルパークラスのstaticメンバー関数を呼び出す
    std::cout << helper<T>::name() << std::endl;
}

int main()
{
    A<int> ai;

    deduce(ai); // aiから推論されるTを表示される
    A<double> ad;

    deduce(ad); // aiから推論されるTを表示する
}
