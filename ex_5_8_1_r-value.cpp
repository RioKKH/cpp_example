#include <iostream>
#include <string>
#include <utility>

void hello(std::string&& name)
{
	std::cout << "Hello, " << name << std::endl;
}

int main()
{
	// 文字列は右辺値
	hello("R2-D2");

	// 変数は左辺値。std::move()を用いて右辺値に変換
	std::string name{"R2-D2"};
	hello(std::move(name));

}
