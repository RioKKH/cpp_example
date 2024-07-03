#include <iostream>
#include <vector>
#include <memory>

// 例1: ポリモーフィズムの利用
class Animal {
public:
    // メンバ関数を純粋仮想関数にすることで、Animalクラスを抽象クラスにする
    virtual void makeSound() = 0;
    // デストラクタを仮想関数にすることで、派生クラスのデストラクタが呼ばれるようにする
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};


class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

// 例2: 動的メモリの割当と遅延初期化
class HeavyResource {
private:
    std::unique_ptr<int[]> largeArray;

public:
    HeavyResource() : largeArray(std::make_unique<int[]>(1000000)) {
        std::cout << "Heavy resource created" << std::endl;
    }
};

class ResourceManager {
private:
    std::unique_ptr<HeavyResource> resource;

public:
    // ResourceManager() : resource(nullptr) {}
    void initializeIfNeeded() {
        if (!resource) {
            resource = std::make_unique<HeavyResource>();
        }
    }
};


// 例3: 所有権の移譲
class UniqueResource {
private:
    std::unique_ptr<int[]> data;

public:
    UniqueResource() : data(std::make_unique<int[]>(100)) {}
    // ムーブコンストラクタとムーブ代入演算子は
    // std::unique_ptrにより自動的に適切に定義される
};


int main() {
    /*
     * 例1: ポリモーフィズムの利用
     * Animalクラスのポインタを使って、DogクラスとCatクラスのインスタンスを生成する。
     * これにより、異なるクラスのインスタンスを同じ型のポインタで扱うことができる
     */
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    for (const auto& animal : animals) {
        animal->makeSound();
    }

    // 例2: 動的メモリの割当と遅延初期化
    ResourceManager manager;
    // 重いリソースは必要になるまで初期化されない
    manager.initializeIfNeeded();

    /*
     * 例3: 所有権の移譲
     * ムーブコンストラクタとムーブ代入演算子を使って、リソースの所有権を移す
     * ポインタを使用することで、所有権の概念を明確に表現できる
     */
    auto res1 = std::make_unique<UniqueResource>();
    auto res2 = std::move(res1); // res1の所有権がres2に移る

    return 0;
}







