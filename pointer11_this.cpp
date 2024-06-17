struct S
{
    void f()
    {
        // thisの型はS *
        S *pointer = this;
        // void f(S &obj);と展開されるため
    }

    void f() const
    {
        // constなメンバー関数の中ではthisの型はS const * になる
        S const *pointer = this;
        // void f(S const &obj) と展開されるため
    }
};

