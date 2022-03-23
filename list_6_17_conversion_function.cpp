#include <iostream>

// 変換関数の使用例
// conversion function
class heap
{
private:
	int* i:

public:
		heap() : i{nullptr}
		{
		}

		~heap();
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
