#include <iostream>
#include <ostream>

namespace my_namespace {

class Point {
private:
  int x_;
  int y_;

public:
  Point(int x, int y) : x_(x), y_(y) {}
  int x() const { return x_; }
  int y() const { return y_; }
  Point operator+(const Point &other) const {
    return Point(x_ + other.x_, y_ + other.y_);
  }
};

std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << "(" << p.x() << ", " << p.y() << ")";
  return os;
}

} // namespace my_namespace

int main() {
  using namespace my_namespace;
  Point p1(3, 4);
  Point p2(5, 6);

  auto p3 = p1 + p2;

  std::cout << "Point p1: " << p1 << std::endl;
  std::cout << "Point p2: " << p2 << std::endl;
  std::cout << "Point p3: " << p3 << std::endl;

  return 0;
}
