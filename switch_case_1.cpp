#include <iostream>

void test1()
{
    int a = 2;
    switch (a + 1)
    {
        case 1:
            std::cout << "a + 1は1です" << std::endl;
            break;

        case 2:
            std::cout << "a + 1は2です" << std::endl;
            break;

        case 3:
            std::cout << "a + 1は3です" << std::endl;
            break;

        // defaultは最後でなくても構わない
        default:
            std::cout << "a + 1 is not any one of 1, 2 or 3." << std::endl;
            break;
    }
}


int FallThrough()
{
    int a = 2;
    switch (a)
    {
        case 1: // FALL THROUGH !!
        case 2: // FALL THROUGH !!
        case 3:
            std::cout << "aは1か2か3です" << std::endl;
            return 0;
            // switch分ではbreak, またはreturn に到達するまで、処理を続ける。
            // そのため、a=2でcase 2に入っても、case 3が実行される。
            // case 3にreturnがあるので、ここで処理が止まる。
    }
    std::cout << "残りの処理" << std::endl;
    return 0;
}

int main()
{
    test1();
    FallThrough();
}

