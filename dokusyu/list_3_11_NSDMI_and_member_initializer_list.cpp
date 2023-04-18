#include <iostream>

class Book
{
private:
	std::string title = "";
	int page = 0;

public:
	Book();
	explicit Book(std::string title, int page);

	void show() const;
};

Book::Book()
	: title("untitled")
{
}

Book::Book(std::string title, int page)
	: title(title), page(page)
{
}

void Book::show() const
{
	std::cout << title << " " << page << std::endl;
}

int main()
{
	Book nsdmi; // NSDMI
	nsdmi.show();
	Book old_edition{"独習C++", 568};
	old_edition.show();
}


