#include <iostream>

class Animal {
public:
    void eat() {
        std::cout << "This animal eats food." << std::endl;
    }
};

class Dog {
private:
    /**
     * 移譲(delegation)とは、クラスのメンバ変数として他のクラスのオブジェクトを持ち、
     * そのオブジェクトのメソッドを呼び出すことで、クラスの機能を拡張する方法です。
     * このようにして、クラスの機能を他のクラスに委譲することで、
     * クラスの再利用性を高めることができます。
     */
    Animal animal;

public:
    void eat() {
        animal.eat(); // 移譲を使ってAnimalクラスのeatメソッドを呼び出す
    }
    void bark() {
        std::cout << "The dog barks." << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat(); // Animalクラスのメソッドを移譲を通じて使用
    myDog.bark();
    return 0;
}





