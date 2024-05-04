#include <iostream>

// 基底クラス
class Bird {
public:
    virtual void fly() {
        std::cout << "Bird is flying." << std::endl;
    }
};

// 派生クラス
class Sparrow : public Bird {
public:
    void fly() override {
        std::cout << "Sparrow is flying." << std::endl;
    }
};

// 別の派生クラス
class Ostrich : public Bird {
public:
    void fly() override {
        throw std::logic_error("Ostrich cannot fly.");
    }
};

void testBirdFlying(Bird& bird) {
    bird.fly();
}

void testBirdFlying2(Bird* bird) {
    try {
        bird->fly();
    } catch (std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    Bird* bird = new Bird();
    testBirdFlying2(bird);

    Bird* sparrow = new Sparrow();
    testBirdFlying2(sparrow);

    /*
     * OstrichはBirdのサブクラスであるが、flyメソッドが異なる振る舞いを
     * するため、リスコフの置換原則に反している。
     * Bird* ostrich = new Ostrich();
     * testBirdFlying(ostrich);
     */


    delete bird;
    delete sparrow;

    return 0;
}


