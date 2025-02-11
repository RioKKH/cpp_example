#include <iostream>

// 右辺値：数値リテラル。値を代入することが出来ないもの。
//         名前を持たない一時的なオブジェクト right hand side value
// 左辺値：変数や引数。値を代入することが出来るもの。
//         明示的に実態のある名前付きオブジェクト left hand side value

template <typename T>
class A
{
public:
	// 関数テンプレートのテンプレートパラメータのみフォワーディング参照となるので
	// U&&はフォワーディング参照だが、T&&はただの右辺値参照
	// クラステンプレートのメンバー関数として関数テンプレートを定義した時に、
	// クラステンプレートのテンプレートパラメータを使ってもフォワーディング参照とはならない
	template <typename U>
	void foo(T&& t, U&& u);
};

int main()
{
	A<int> a;
	int i = 0;
	a.foo(i, 0); // エラー。iは左辺値なので右辺値参照には渡せない

	return 0;
}
