struct C
{
    int data {};

    void set(int n)
    {
        // メンバー関数は自分を呼び出したクラスのオブジェクトへの参照を知っている
        // その参照にアクセスする方法がthis
        // thisキーワードはクラスのメンバー関数の中で使うと、メンバー関数を
        // 呼び出したクラスのオブジェクトへのポインターとして扱われる
        C *pointer = this;
        this->data = n;
    }

    // thisは歴史的な経緯でポインターになっている
    // referenceのほうが本来は好ましい
    // もしreferenceに固定したいのであれば、以下のようにする
    void f()
    {
        auto &this_ref = *this;
    }
};
