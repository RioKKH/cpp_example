#include <iostream>
#include <vector>

// 例1: ポリモーフィズムの利用
class Animal {
public:
    // メンバ関数を純粋仮想関数にすることで、Animalクラスを抽象クラスにする
    virtual void makeSound() = 0;
    // デストラクタを仮想関数にすることで、派生クラスのデストラクタが呼ばれるようにする
    virtual ~Animal() {}
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
    int *largeArray;

public:
    HeavyResource() : largeArray(new int[1000000]) {
        std::cout << "Heavy resource created" << std::endl;
    }
    ~HeavyResource() { delete[] largeArray; }
};

class ResourceManager {
private:
    HeavyResource *resource;

public:
    ResourceManager() : resource(nullptr) {}
    void initializeIfNeeded() {
        if (!resource) {
            resource = new HeavyResource();
        }
    }
    ~ResourceManager() { delete resource; }
};


// 例3: 所有権の移譲
class UniqueResource {
private:
    int* data;

public:
    UniqueResource() : data(new int[100]) {}
    ~UniqueResource() { delete[] data; }
    /**
     * @brief ムーブコンストラクタ
     * @param other ムーブ元のオブジェクト
     * @note UniqueResource&&は右辺値参照を表す。これにより、一時オブジェクトや
     * std::moveで明示的に移動されるオブジェクトを受け取ることができる。
     * コンストラクタはother.dataのポインタを直接コピーし、所有権を移転する。
     * その後、other.dataをnullptrに設定することで、元のオブジェクトがデストラクタ
     * で誤ってメモリを開放するのを防ぐ。
     */
    UniqueResource(UniqueResource&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }
    /**
     * @brief ムーブ代入演算子
     * @param other ムーブ元のオブジェクト
     * @return ムーブ後のオブジェクト
     * @note
     * -# ムーブ代入演算子はムーブコンストラクタと同様に、所有権を移転する
     * -# 自己代入チェックを行い、オブジェクトが自分自身に代入されるのを防ぐ
     * -# 現在保持しているリソースを開放する (delete [] data)
     * -# 新しリソースの所有権を取得する (data = other.data)
     * -# 元のオブジェクトのポインタをnullptrに設定する (other.data = nullptr)
     * -# *thisを返すことで、連鎖代入(a = b = c)を可能にする
     */
    UniqueResource& operator=(UniqueResource&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};


int main() {
    /*
     * 例1: ポリモーフィズムの利用
     * Animalクラスのポインタを使って、DogクラスとCatクラスのインスタンスを生成する。
     * これにより、異なるクラスのインスタンスを同じ型のポインタで扱うことができる
     */
    std::vector<Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for (Animal* animal : animals) {
        animal->makeSound();
    }

    // メモリリークを防ぐため、動的に割り当てたメモリを解放する
    for (Animal* animal : animals) {
        delete animal;
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
    UniqueResource res1;
    UniqueResource res2 = std::move(res1); // res1の所有権がres2に移る

    return 0;
}







