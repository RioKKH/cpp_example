#include <iostream>
#include "lib.hpp"

int main()
{
    classstruct st1;
    test t1, t2;
    // st.show();
    t1 = st1.getTest();

    classstruct *st2 = new classstruct();
    t2 = st2->getTest();

    std::cout << "t1.a: " << t1.a << std::endl;
    std::cout << "t1.b: " << t1.b << std::endl;

    t1.a = 3;

    std::cout << "t1.a: " << t1.a << std::endl;

    std::cout << "t2.a: " << t2.a << std::endl;
    std::cout << "t2.b: " << t2.b << std::endl;

    delete st2;
    return 0;
}

