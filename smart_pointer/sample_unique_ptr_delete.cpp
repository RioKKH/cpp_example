#include <iostream>
#include <memory>

int main()
{
    {
        std::unique_ptr<int> ptr(new int(10));
    } // ここでptrのdestructorが呼ばれ、自動的に解放される
    
    // 引数無しやnullptrを引数としてreset関数を呼んでも、明示的に解放出来る
    std::unique_ptr<int> ptr2(new int (10));
    std::cout << *ptr2 << std::endl;
    ptr2.reset();
    // std::cout << *ptr2 << std::endl; // Nothing to show

    return 0;
}


