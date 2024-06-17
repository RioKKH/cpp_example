struct C
{
    int data {};

    void set(int n)
    {
        data = n;
    }
};

/** 隠し引数
内部的には以下のような隠し引数を持つコードが生成される(多分正確ではない)
つまり、メンバー関数は自分を呼び出したクラスのオブジェクトへの参照を知っている
---> この参照にアクセスする方法がthisキーワード
void set(C &obj, int n)
{
    obj.data = n;
}
*/

int main()
{
    C a;
    C b;

    // a.dataを変更
    a.set(1);
    // b.dataを変更
    b.set(2);
}
