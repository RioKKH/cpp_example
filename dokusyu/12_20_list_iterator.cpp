#include <iostream>
#include <list>

template <typename T>
void print_list(const std::list<T>& il)
{
    for (auto iter = il.begin(); iter != il.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<std::int32_t> il = {0, 1, 2, 3, 4};
    print_list(il);

    auto top = il.begin(); // topは0を指す

    auto next = il.begin(); // nextは0を指すが
    ++next;                 // ++することでnextが指すものは1に変わる

    auto bottom = il.end(); // bottomは4を指すが
    --bottom;               // --することでbottomが指すものは3に変わる

    il.erase(top);   // 削除された要素を指すtopは無効になるが
    il.push_back(5); // それ以外(next, bottom)は無効とならない
    print_list(il);

    for (auto iter = next; iter != bottom; ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}
