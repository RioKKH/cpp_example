#include <iostream>
#include <string>
#include <vector>

class product
{
private:
	int         id;
	std::string name;
	int         price;

public:
	explicit product(int id, std::string name, int price)
		: id(id), name(name), price(price)
	{
	}

	// NSDMIがうまく動作しなかったので、default constructorを実装した
	product() : product(0, "not available", 0)
	{
	}

	void show() const;
};

void product::show() const
{
	std::cout << id << std::endl;
	std::cout << name << std::endl;
	std::cout << price << std::endl;
	std::cout << std::endl;
}


int main()
{
	std::vector<product> p =
	{
		product{1, "smart phone", 60000},
		product{2, "tablet", 35000},
	};

	p.push_back(product{});
	p.push_back(product{});

	for (const auto& element : p)
	{
		element.show();
	}
}
