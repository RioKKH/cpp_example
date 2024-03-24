class MyClass {
    public:
        // コンストラクタ
        MyClass(const MyClass &source);  // コピー
        MyClass(MyClass &&source);       // ムーブ
        // コンストラクタの引数が右辺値参照で解決できる場合には
        // それはムーブであると解釈される
        // コピーコンストラクタでは引数がconst修飾されているが、
        // ムーブコンストラクタでは引数の値が書き換えられる事も
        // あるのでconst修飾されない。スマートポインタがその例。

        // 代入演算子
        MyClass& operator=(const MyClass &source);  // コピー
        MyClass& operator=(MyClass &&source);       // ムーブ
        // 代入演算子の右辺が右辺値参照で解決できる場合には
        // それはムーブできると解釈される
};



