#include <iostream>
using namespace std;

int main()
{
    char *p = NULL;
    // 初期化したとしてもダングリングポインタであることに変わりはない
    // モダンC++では、NULLの代わりにどこも指していない事を
    // 明示的に示すnullptrを使う
    *p = 'A';
    cout << *p << endl;
    // Segmentation fault
    return 0;
}
