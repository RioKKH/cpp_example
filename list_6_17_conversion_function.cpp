#include <iostream>

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
