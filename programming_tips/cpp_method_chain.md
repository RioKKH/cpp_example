# C++

## メソッドチェーン (Method Chaining)

### 解説

メソッドチェーン（Method  Chaining）は、オブジェクト指向プログラミングにおいて、複数のメソッド呼び出しを一連の操作として連結するテクニックです。このテクニックは、特にフルエントインターフェースの設計でよく用いられます。フルエントインターフェースは、コードの可読性と書きやすさを高めることを目的としています。

### メソッドチェーンの例 - MyClass& increment()

```c++
class MyClass
{
private:
    int value;
    
public:
    MyClass(int value)
    {
        thsi->value = value;
    }
    
    // オブジェクトの不要なコピーを避けてオブジェクトへの参照を返すことで、
    // コピーコンストラクタの呼び出しなどのパフォーマンス低下要因を避けることが出来る
    MyClass& increment()
    {
        this->value++; // メンバ変数の値をインクリメント
    	return *this   // thisでのデリファレンスを返す
    }
};

int main()
{
    MyClass obj(10);
    
	// ３回インクリメントすることでthis->valueは13になる。
    obj.increment().increment().increment();
}

```

`MyClass`の`increment`メソッドは、メソッドチェーンをサポートするための良い例です。このメソッドは、オブジェクト自身（`*this`）への参照を返します。これにより、同じオブジェクトに対する複数のメソッド呼び出しを一つの連続した表現で行うことができます。

