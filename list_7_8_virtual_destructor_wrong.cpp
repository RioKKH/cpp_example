#include <iostream>

// virtual destructor
// 動的確保した継承を使ったオブジェクトを解放するときに、
// 正しいデストラクタ−が呼ばれるようにするための機能

// 仮想デストラクタを使わないためにデストラクタ−の呼び出しが
// 不完全になってしまうプログラム例
class Base
{
public:
    ~Base()
    {
        std::cout << "Base::~Base()" << std::endl;
    }
};

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "Derived::~Derived()" << std::endl;
    }
};

Base* allocate()
{
    // 派生クラスを動的確保するが、関数の戻り値の型が基底クラスへのポインター
    // になっているので、暗黙変換によって基底クラスへのポインターが返される。
    return new Derived{};
}

int main()
{
    auto ptr = allocate(); // 基底クラスへのポインターが返される

    delete ptr; // 注意：コンパイルできるが問題あるコード

    return 0;
}
    
