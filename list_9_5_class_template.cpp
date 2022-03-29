#include <iostream>

// メンバー関数を持たないクラステンプレートは殆ど通常のクラスと
// 同じように扱うことが出来る
template <typename T>
class vector2d
{
public:
    // テンプレートパラメータで渡された型でメンバー変数を宣言
    T x;
    T y;

    // このメンバー関数は私の方で追加したもの。例題のコンセプトが
    // 崩れるが、特に問題になるようなメンバー関数ではないと思う。
    void show() const
    {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
};

void show(int v)
{
    std::cout << "int " << v << std::endl;
}

void show(float v)
{
    std::cout << "float " << v << std::endl;
}

int main()
{
    // float型の2次元ベクトルを定義
    vector2d<float> f2d{10.0f, 20.0f};

    // int型の2次元ベクトルを定義
    vector2d<int> i2d{10, 20};

    // エラー。同じクラステンプレートを使っているが、テンプレート引数が
    // 異なるので別の型
    // i2d == f2d

    f2d.x = -10.0f; // メンバーへのアクセス方法は通常のクラスと同じ

    f2d.show();
    i2d.show();
    show(i2d.y); // int型のオーバーロードが呼ばれる
    show(f2d.y); // float型のオーバーロードが呼ばれる
}
