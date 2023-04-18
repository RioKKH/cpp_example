#include <iostream>

class product
{
private:
	int price;

public:
	product(int price) : price(price) {}; // 自動インライン化

	inline int get_price() const;
	inline void set_price(int price);
};

// product::product(int price) : price(price) {}

int product::get_price() const { return price; }

void product::set_price(int price) { this->price = price; }


int main()
{
	product A(100);
	return 0;
}

