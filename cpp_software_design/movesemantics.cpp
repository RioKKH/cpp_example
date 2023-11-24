#include <iostream>
#include <algorithm> // for std::swap

class DynamicArray {
public:
    int* data;
    size_t size;

    // コンストラクタ
    DynamicArray(size_t size) : size(size), data(new int[size]) {}

    // デストラクタ
    ~DynamicArray() {
        delete[] data;
    }

    // コピーコンストラクタ（ディープコピー）
    DynamicArray(const DynamicArray& other)
        : size(other.size), data(new int[other.size])
    {
        std::copy(other.data, other.data + size, data);
    }

    // ムーブコンストラクタ
    DynamicArray(DynamicArray&& other) : size(0), data(nullptr) {
        // リソースの所有権を移動
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;
    }

    // ムーブ代入演算子
    DynamicArray& operator=(DynamicArray&& other) {
        if (this != &other) {
            delete[] data;

            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // ユーティリティ関数
    void fill(int value) {
        std::fill_n(data, size, value);
    }
};

int main() {
    DynamicArray arr1(10); // 通常のコンストラクタ
    arr1.fill(1);
    std::cout << "arr1: ";
    for (size_t i = 0; i < 10; ++i) {
        std::cout << arr1.data[i] << ' ';
    }
    std::cout << std::endl;

    DynamicArray arr2 = arr1; // コピーコンストラクタを使用
    arr2.fill(2);
    std::cout << "arr1: ";
    for (size_t i = 0; i < 10; ++i) {
        std::cout << arr2.data[i] << ' ';
    }
    std::cout << std::endl;
     
    // arr2はムーブ代入演算子でarr3に移動されたので、arr2はもう使えません
    DynamicArray arr3(10);
    arr3 = std::move(arr2); // ムーブ代入演算子を使用

    // arr1はムーブコンストラクタでarr2に移動されたので、arr1はもう使えません
    DynamicArray arr4(std::move(arr1)); // ムーブコンストラクタを使用
    arr4.fill(3);

    std::cout << "arr3: ";
    for (size_t i = 0; i < 10; ++i) {
        std::cout << arr3.data[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "arr4: ";
    for (size_t i = 0; i < 10; ++i) {
        std::cout << arr4.data[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
