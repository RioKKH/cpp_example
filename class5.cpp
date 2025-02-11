#include <iostream>

class ANIMAL {
private:
    int age;

public:
    ANIMAL(int a) : age(a) {}
    int getAge() { return age; }
};
        

class ZOO {
private:
    ANIMAL *a;

public:
    ZOO(int age) : a(new ANIMAL(age)) {}
    ANIMAL b = {10};
    ~ZOO() { delete a; }
    int getAge() { return a->getAge(); }
    int getAgeb() { return b.getAge(); }
};

int main() {
    ZOO z(5);
    std::cout << z.getAge() << std::endl;
    std::cout << z.getAgeb() << std::endl;

    return 0;
}
