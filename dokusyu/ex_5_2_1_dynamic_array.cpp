#include <iostream>
#include <string>

class product
{
private:
	// NSDMIを使ってデフォルト値を指定しておけば、配列の長さよりも
	// 配列の初期化リストのほうが短かった場合には、不足分は
	// デフォルトコンストラクターをこれらの値を使って初期化される
	int         id = 0;
	std::string name = "not available";
	int         price = 0;

public:
	explicit product(int id, std::string name, int price)
		: id(id), name(name), price(price)
	{
	}

	// NSDMIがうまく動作しなかったので、default constructorを実装した
	product() : product(0, "not available", 0)
	{
	}
};

int main()
{
	product p[4] =
	{
		product{1, "smart phone", 60000},
		product{2, "tablet", 35000},
	};
}
