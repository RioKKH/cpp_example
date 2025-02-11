#include <iostream>

typedef struct rectangle {
    int length;
    int breadth;
} rectangle;

void show(rectangle *r) {
// void show(const rectangle &r) {
    std::cout << __func__ << ": Length: " << r->length << std::endl;
    std::cout << __func__ << ": Breadth: " << r->breadth << std::endl;
    // std::cout << __func__ << ": Length: " << r.length << std::endl;
    // std::cout << __func__ << ": Breadth: " << r.breadth << std::endl;
}

int area(rectangle *r) {
// int area(const rectangle &r) {
    return r->length * r->breadth;
    // return r.length * r.breadth;
}

int main() {
    rectangle r = {10, 5};

    rectangle *pr;
    pr = &r;

    int length = pr->length;
    int breadth = pr->breadth;
    std::cout << __func__ << ": Length: " << length << std::endl;
    std::cout << __func__ << ": Breadth: " << breadth << std::endl;
    show(&r);

    std::cout << "### Change length and breadth ###" << std::endl;

    // length, breadthの値を変更してもrの値は変わらない
    length = 20;
    breadth = 10;
    std::cout << __func__ << ": Length: " << length << std::endl;
    std::cout << __func__ << ": Breadth: " << breadth << std::endl;
    show(&r); // rの値は変わらない

    return 0;
}

