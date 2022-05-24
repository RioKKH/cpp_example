#ifndef LIB_HPP
#define LIB_HPP

#include <iostream>

typedef struct
{
    int a;
    int b;
} test;

class classstruct
{
private:
    test t;

public:
    explicit classstruct();
    ~classstruct();
    void show(void);
    int geta(void) const;
    int getb(void) const;
    test getTest(void) const;
};

#endif // LIB_HPP
