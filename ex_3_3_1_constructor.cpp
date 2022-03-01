#include <iostream>
#include <string>

class Book
{
private:
	std::string title;
	std::string writer;
	int price;

public:
	Book();
	Book(std::string title, std::string writer, int price);
};

Book::Book()
{
	std::cout << "default constructor" << std::endl;
}

Book::Book(std::string title, std::string writer, int price)
	: title(title), writer(writer), price(price)
{
}

int main()
{
	Book book("abc", "Cristy", 600);

	return 0;
}



