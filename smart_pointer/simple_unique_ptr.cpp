#include <iostream>

template <typename T>
class unique_ptr
{
private:
	T *ptr = nullptr;

public:
	unique_ptr() { }
	explicit unique_ptr(T *ptr) : ptr(ptr) { }
	~unique_ptr() { delete ptr; }

	// コピーは禁止
	unique_ptr(const unique_ptr &) = delete;
	unique_ptr &operator = (const unique_ptr &) = delete;

	// ムーブ
	unique_ptr(unique_ptr &&r) : ptr(r.ptr)
	{
		r.ptr = nullptr;
	}

	unique_ptr &operator = (unique_ptr &&r)
	{
		delete ptr;
		ptr = r.ptr;
		r.ptr = nullptr;
	}

	T &operator * () noexcept { return *ptr; }
	T *operator -> () noexcept { return ptr; }
	T *get() noexcept { return ptr; }
};

int main()
{
	unique_ptr<int> ptr1(new int(10));
	std::cout << *ptr1 << std::endl;

	// unique_ptr<int> ptr2(ptr1); // error
	
	unique_ptr<int> ptr3(std::move(ptr1));
	std::cout << *ptr3 << std::endl;

	unique_ptr<int> ptr4;
	ptr4 = std::move(ptr3);
}


