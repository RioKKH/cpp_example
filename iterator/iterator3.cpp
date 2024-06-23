template <typename A, typename B, typename C>
struct S
{
    void f()
    {
        S s;
        // クラステンプレートの中でクラス名を使うと、テンプレート実引数
        // をそれぞれ指定したものと等しくなる。
        // つまり、S = S<A, B, C>となり、
        // テンプレート実引数を指定したものと等しい
    }
};
