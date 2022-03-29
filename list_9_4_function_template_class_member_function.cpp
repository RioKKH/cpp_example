#include <iostream>

class S
{
private:

public:
    // 宣言と同時に定義も与える場合
    template <typename T>
    void foo(T value)
    {
        std::cout << "S::foo() value: " << value << std::endl;
    }

    // 宣言と定義を分ける場合
    template <typename T>
    void bar(T value);
};

// 普通のメンバー関数定義にtemplateがついただけ
template <typename T>
void S::bar(T value)
{
    std::cout << "S::bar() value: " << value << std::endl;
}

int main()
{
    S s;
    s.foo<int>(0);
    s.bar<float>(0.0f);
}
