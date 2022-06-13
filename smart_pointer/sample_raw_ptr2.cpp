#include <memory>

class A
{
private:
    int *ptr;

public:
    A(int val_)
    {
        if (val_ > 0)
        {
            ptr = new int (val_);
        }
    }
    ~A()
    {
        delete ptr;
    }
};

int main()
{
    // A()のコンストラクタでnewが呼ばれない
    A Hoge(-1);

    return 0;
} // error : newしていないポインタに対するdestructorのdeleteは未定義！
