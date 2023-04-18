#include <iostream>

// 変換関数の使用例
// conversion function
class heap
{
private:
	int* i;

public:
		heap() : i{nullptr}
		{
		}

		~heap()
		{
			delete i;
		}

		bool create();

		// bool型に変換する
		operator bool() const;
};

bool heap::create()
{
	// true/falseになるので、if文でそのまま条件分岐できる
	if (*this) // bool型への変換関数が呼ばれる
	{
		return false;
	}

	i = new int{};
	*i = 0;
	return true;
}

heap::operator bool () const // (と)を合わせて()で変換関数演算子
{
	return i != nullptr;
}

int main()
{
	heap h;

	if (!h)
	{
		std::cout << "変換関数がfalseを返しました" << std::endl;
	}

	std::cout << "heap::create()呼び出し" << std::endl;
	h.create();

	if (!h)
	{
		std::cout << "変換関数がfalseを返しました" << std::endl;
	}

	std::cout << "終了" << std::endl;

	return 0;
}
