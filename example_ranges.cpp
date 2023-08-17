#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>

int oldStyle()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> result;

    std::copy_if(vec.begin(), vec.end(), std::back_inserter(result),
            [](int n) { return n % 2 == 0; });

    std::transform(result.begin(), result.end(), result.begin(),
            [](int n) { return n * 2; });

    for (const auto val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

int newStyle()
{
    // rangesを用いて同様の処理を実装する。
    // 非常にRのtidyverseと感触が近い。
    // データの変換やフィルタリングをパイプラインとして表現出来るようになる
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto result = vec | std::views::filter([](int n) { return n % 2 == 0; })
                      | std::views::transform([](int n) { return n * 2; });
    for (const auto val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

int main()
{
    std::cout << "Conventional STL version" << std::endl;
    newStyle();
    std::cout << "New Ranges version" << std::endl;
    newStyle();
    return 0;
}
