#include <iostream>

class Animal {
public:
    void eat() {
        std::cout << "This animial eats food." << std::endl;
    }
};

/**
 * DogクラスはAnimalクラスを継承します。継承することによって、
 * 基底クラスの属性やメソッドを派生クラスが引き継ぐ事が可能になります。
 * 継承は強い結び付きを生じさせる為、クラス間の依存関係が高まり、
 * システムの柔軟性が損なわれる事がある。
 */
class Dog : public Animal {
public:
    void bark() {
        std::cout << "The dog barks." << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();
    myDog.bark();
    return 0;
}
