#include <iostream>
#include <vector>

/**
 * 非静的メンバー変数の初期化子
 * Non Static Data Member Initializer : NSDMI
 */
class S
{
public:
	int answer = 42;        // NSDMI
	std::vector<int> answer2 = {1, 2, 3}; // NSDMI
	// float e(2.73); // NDSMI
	float pi{3.14159265f}; // NSDMI
};

int main()
{
	S s;
	std::cout << "s.answer: " << s.answer << std::endl;
	for (const auto& a : s.answer2)
	{
		std::cout << a << std::endl;
	}
	// std::cout << "s.e: " << s.e << std::endl;
	std::cout << "s.pi: " << s.pi << std::endl;
}


