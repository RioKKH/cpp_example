#include <iostream> // std::cout
#include <memory>   // std::unique_ptr
#include <utility>

class A
{
private:

public:
	A()
	{
		std::cout << "constructor" << std::endl;
	}

	~A()
	{
		std::cout << "destructor" << std::endl;
	}
};

std::unique_ptr<A> allocate()
{
	std::cout << "allocate()" << std::endl;
	std::unique_ptr<A> ptr{new A{}};

	// メモリ領域の所有権を戻り値として関数スコープの外側に移動する
	return std::move(ptr);
}


int main()
{
	{
		// 空のstd::unique_ptr。nullptrで初期化される
		std::unique_ptr<A> ptr;

		std::cout << "関数呼び出しの前" << std::endl;

		ptr = allocate(); // allocate()が確保したメモリ領域の所有権を受け取る

		std::cout << "関数呼び出しの後" << std::endl;
	}

	std::cout << "スコープの後" << std::endl;
}
		

