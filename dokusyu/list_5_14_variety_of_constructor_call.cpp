#include <iostream>
#include <string>

class A
{
private:
	int m_v;
	std::string m_n;

public:
	A(int, std::string);
	A(float);
};

A::A(int v, std::string n)
	: m_v(v)
	, m_n{n} // OK。メンバー初期化リストでも{}を使うことができる
{
}

A::A(float)
	: A{-1, "float"} // OK。委譲コンストラクターでも{}を使うことができる
{
}


int main()
{
	A ap(42, "0"); // 普通に()を使う
	A ab{42, "0"}; // OK。()の代わりに{}を使うことができる

	A bp = A(42, "0"); // OK。関数形式の明示的な型変換
	A bb = A{42, "0"}; // OK。bpの初期化と同等

	A cp = (42, "0"); // error. A(int, std::string)の呼び出しにはならない
	A cb = {42, "0"}; // OK。bbの初期化と同等

	A dp = (42, 0.0) // 要注意。A(int, std::string)ではなくてA(float)が呼ばれる
	A db = {42, 0.0} // エラー。doubleからstd::stringへの変換はできない

	double pi = 3.1415926536;
	A ep(pi); // OKだがdoubleからfloatへの暗黙変換が行われる
	A eb{pi}; // エラー。doubleからfloatへは安全に変換できない
}
	
