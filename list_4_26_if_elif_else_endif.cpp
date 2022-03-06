#include <iostream>

#if defined(__cplusplus) // ifdef __cplusplus
extern "C" {
#endif

// C言語の宣言など

#if defined(__cplusplus) // ifdef __cplusplus
}
#endif

#define HOGE

int main()
{
#if defined(HOGE) // --> 1
	std::cout << "defined(HOGE)はtrueです" << std::endl;
#else
	std::cout << "defined(HOGE)はflaseです" << std::endl;
#endif
}

