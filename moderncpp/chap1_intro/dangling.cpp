#include <iostream>
using namespace std;

int main()
{
    char *p;

    *p = 'A';
    cout << *p << endl;
    // The above code will cause a segmentation fault
    // because the pointer p is not initialized and
    // it is pointing to a random memory location.
    // So, the statement *p = 'A'; will cause a
    // segmentation fault.
    // To fix this, we need to allocate memory to the
    // pointer p before using it.
    // For example:
    // p = new char;
    // *p = 'A';
    // cout << *p << endl;
    // delete p;

    return 0;
}
