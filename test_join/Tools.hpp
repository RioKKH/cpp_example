#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <vector>
#include <string>
#include <sstream>

// テンプレート関数を明示的に実体化することが出来るのであれば
// hppとcppで定義と実装を分けることが出来るが、ありえるすべて
// のケースを書き出すことが出来ないのであれば、諦めてヘッダ
// ファイルの中で完結させる必要がある
// 参考URL：https://theolizer.com/cpp-school2/cpp-school2-3/
template <typename Iter>
std::string join(Iter begin, Iter end, std::string const& separator)
{
	std::ostringstream result;
	if (begin != end)
	{
		result << *begin++;
	}
	while (begin != end)
	{
		result << separator << *begin++;
	}
	return result.str();
}

#endif // TOOLS_HPP
