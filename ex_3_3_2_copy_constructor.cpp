#include <iostream>
#include <string>

class Book
{
private:
	std::string title;
	std::string writer;
	int price;

public:
	// 暗黙のコンストラクター呼び出しを避けるためにexplicit指定子を使う
	explicit Book();
	explicit Book(std::string title, std::string writer, int price);
	explicit Book(const Book& other);

	void show() const;
};

Book::Book()
{
	std::cout << "default constructor" << std::endl;
}

Book::Book(std::string title, std::string writer, int price)
	: title(title), writer(writer), price(price)
{
}

/**
 * コピーコンストラクターでは、メンバー初期化リストを使って
 * メンバー変数ごとにコピーする必要がある。
 */
Book::Book(const Book& other) // コピーコンストラクター
	: title(other.title), writer(other.title), price(other.price)
{
	std::cout << "copy consturctor" << std::endl;
}

void Book::show() const
{
	std::cout << title << " " << writer << " " << price << std::endl;
}


int main()
{
	Book book1("abc", "Cristy", 600);

	Book book2(book1); // copy
	book2.show();

	return 0;
}

