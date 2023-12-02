#include <iostream>

/**
 * リスコフの置換原則(LSP)を満たすようにコードを書き換える。
 * Birdクラスのflyメソッドの振る舞いを全てのサブクラスで一貫性を
 * 持たせるか、または飛べない鳥のための別の気候を提供する必要が
 * ある。
 *
 * 1つのアプローチとして、BirdクラスにcanFlyというメソッドを追加し、
 * それを利用して鳥が飛べるかどうかを判断する方法がある。
 * これにより、全ての取りが一貫したインターフェースを持ちながら、
 * 飛べない鳥についても適切に扱う事が出来るようになる。
 */

// 基底クラス
class Bird {
public:
    // 鳥が飛べるかどうかを示すメソッド
    virtual bool canFly() {
        return true;
    }

    void fly() {
        if (canFly()) {
            std::cout << "Bird is flying." << std::endl;
        } else {
            std::cout << "This bird can't fly." << std::endl;
        }
    }
};

// 派生クラス
class Sparrow : public Bird {
public:
    // スズメはとべるので、canFlyメソッドは更新しない
};

// 別の派生クラス
class Ostrich : public Bird {
public:
    // ダチョウはとべないので、canFlyメソッドをオーバーライドする
    bool canFly() override {
        return false;
    }
};


void testBirdFlying(Bird* bird) {
    bird->fly();
}

int main() 
{
    Bird* bird = new Bird();
    testBirdFlying(bird);

    Bird* sparrow = new Sparrow();
    testBirdFlying(sparrow);

    Bird* ostrich = new Ostrich();
    testBirdFlying(ostrich);

    delete bird;
    delete sparrow;
    delete ostrich;

    return 0;
}


