#include <iostream>

class printer {
   public:
    printer() { std::cout << "Constructor: Hello World!" << std::endl; }

    // This is a const member function
    void print() const {
        std::cout << "Const method: Hello World!" << std::endl;
    }
};

int main() {
    printer p[10];

    for (const auto& i : p) {
        i.print();
    }
}
