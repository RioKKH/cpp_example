#include <iostream>

// 関数オブジェクトで用いる
// function object

// 呼び出されるたびにカウントして現在地を返すカウンタークラス
class Counter
{
private:
	int value;

public:
	Counter() : value{0} {}

	// Overload of function call operator
	int operator()(); // 引数を受け取らない関数呼び出し演算子のオーバーロード
	int operator()(int n); // 仮引数1つの関数呼び出し演算子のオーバーロード

	void show() const;
};


// 引数が無いときにはインクリメントして今のカウンター値を返す
int Counter::operator()()
{
	return ++value;
}

// 引数で具体的な増減値が与えられたときにはその数だけ増減させる
int Counter::operator()(int n)
{
	return value += n;
}

void Counter::show() const
{
	std::cout << "Counter.value = " << value << std::endl;
}


int main()
{
	Counter c;

	c();
	c.show();
	c();
	c.show();
	c();
	c.show();
	c(-3);
	c.show();
}
