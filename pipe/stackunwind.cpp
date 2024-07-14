#include <iostream>
#include <cstdlib>

class Resource {
private:
    int m_id;

public:
    Resource(int id) : m_id(id) {
        std::cout << "Resource " << m_id << " acquired\n";
    }
    ~Resource() {
        std::cout << "Resource " << m_id << " released\n";
    }
};

/**
 * This function creates two local objects of class Resource.
 * When the function returns, the destructors of the local objects are called.
 * stack unwinding happens.
 */
void function_with_local_objects() {
    Resource r1(1);
    Resource r2(2);
    std::cout << "Function with local objects\n";
}

/**
 * This function calls exit() which terminates the program immediately.
 * The destructors of local objects are not called.
 */
void function_with_exit() {
    Resource r3(3);
    std::cout << "Calling exit()\n";
    exit(0);
}

int main() {
    std::cout << "Case 1: Normal function execution\n";
    function_with_local_objects();

    std::cout << "\nCase 2: Using exit()\n";
    function_with_exit();

    std::cout << "This line will not be executed\n";
    return 0;
}



