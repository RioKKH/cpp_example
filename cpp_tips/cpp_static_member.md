# C++

## class のメンバ関数に `static` または `const`を付けた場合の挙動

### 解説

1. static メンバ関数
   - クラスのインスタンスに依存せず、クラス自体に属する関数
   - インスタンスを作成せずにクラス名を使って直接呼び出す事が出来る
   - `static`メンバ関数内では、クラスの非`static`メンバ変数やメンバ関数にアクセスすることは出来ない
   - `static`メンバ関数は、クラスの`static`メンバ変数のみにアクセスできる
2. const メンバ関数
   - メンバ関数が対象のオブジェクトの状態を変更しないことを示す
   - `const`メンバ関数内では、オブジェクトのメンバ変数を変更することはできない
   - `const`メンバ関数内で呼び出せるのは、他の`const`メンバ関数のみ
   - オブジェクトが`const`として宣言された場合、そのオブジェクトでは`const`メンバ関数のみ呼び出すことが出来る
3. static const メンバ関数
   - `static`と`const`の両方の性質をもつメンバ関数
   - クラスのインスタンスに依存せず、クラス自体に属する
   - メンバ関数内でオブジェクトの状態を変更することはできない
   - `static const`メンバ関数は、クラスの`static const`メンバ変数のみにアクセスできる



### コード例

```c++
class MyClass {
private:
    static const int value = 10;
    
public:
    static const int getValue() {
        return value;
    }
};

int main() {
    int result = MyClass::getValue();
    // MyClassクラスのインスタンスを作成せずにMyClass::getValue()メンバ関数を呼び出す事が出来ている
    std::cout << result << std::endl;
    return 0;
}
```

クラスのインスタンスに依存しない低数値を提供するメンバ関数を定義できる。これはクラス内の低数値を外部から安全にアクセスできるようにするのに便利。

具体的にはシングルトンパターンで使われる。シングルトン(Singleton pattern)は、クラスのインスタンスが1つしか存在しないことを保証するためのデザインパターンとなる。これはグローバルな状態を持つオブジェクトや、リソースを一元管理する場合などに使用される。

以下にコード例を示す

```c++
class Singleton {
private:
    static Singleton* instance;
    Singleton() {} // コンストラクタをprivateにして、がいぶからのインスタンシエーションを禁止する

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    
    void someMethod() {
        // シングルトンオブジェクトに対する処理
        std::cout << "Singleton method called." << std::endl;
    }
    
    ~Singleton() {
        delete instance;
        instance = nullptr;
    }
};

Singleton* Singleton::instance == nullptr; // static メンバ変数の初期化

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    
    s1->someMethod(); // 出力 Singleton method called.
    s2->someMethod(); // 出力 Singleton method called.
    
    // s1とs2は同じインスタンスを指している
    std::cout << (s1 == s2) << std::endl; // 出力: 1 (true)
    
    return 0;
}
```

スタティックローカル変数を用いたSingleton patternの実装例

```c++
class Singleton {
private:
    Singleton() {}  // コンストラクタをprivateにして、外部からのインスタンス化を禁止

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void someMethod() {
        // シングルトンオブジェクトに対する処理
        std::cout << "Singleton method called." << std::endl;
    }

    // コピーコンストラクタとコピー代入演算子を削除して、コピーを禁止
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.someMethod();  // 出力: Singleton method called.
    s2.someMethod();  // 出力: Singleton method called.

    // s1とs2は同じインスタンスを参照している
    std::cout << (&s1 == &s2) << std::endl;  // 出力: 1 (true)

    return 0;
}
```

Singletonオブジェクトの参照を返すように変更されている。この理由は以下の通り。

ポインタを返す場合：

- ポインタは、オブジェクトのアドレスを保持し、そのオブジェクトを指し示します。
- ポインタを受け取る側は、オブジェクトの所有権を持つことになります。つまり、オブジェクトのメモリ管理に責任を持ちます。
- ポインタを受け取る側は、オブジェクトが有効であることを確認する必要があります。ポインタがnullptrかどうかのチェックが必要になることがあります。
- ポインタを介してオブジェクトにアクセスするには、`->`演算子を使用します。

参照を返す場合：

- 参照は、オブジェクトに別名をつけるようなものです。参照先のオブジェクトを直接扱うことができます。
- 参照を受け取る側は、オブジェクトの所有権を持ちません。オブジェクトのライフタイムは、参照元のスコープに依存します。
- 参照は、常に有効なオブジェクトを指している必要があります。nullptrのような無効な状態を表現できません。
- 参照を介してオブジェクトにアクセスするには、`.`演算子を使用します。

Singletonパターンの文脈では、`getInstance()`関数が参照を返す場合、以下のような利点があります。

1. シングルトンオブジェクトの所有権は、`getInstance()`関数内のスタティックローカル変数が持ちます。呼び出し側は、所有権を管理する必要がありません。
2. 参照を返すことで、シングルトンオブジェクトが常に有効であることが保証されます。nullptrチェックが不要になります。
3. 参照を使用することで、シングルトンオブジェクトへのアクセスがシンプルになります。`->`演算子ではなく、`.`演算子を使用できます。