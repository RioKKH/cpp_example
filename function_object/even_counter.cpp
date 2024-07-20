#include <iostream>
#include <vector>
#include <algorithm>

class EvenCounter {
private:
    int count_;

public:
    EvenCounter() : count_(0) {}

    void operator()(int x) {
        if (x % 2 == 0) {
            ++count_;
        }
    }

    int getCount() const { return count_; }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // std::for_each()は使用した関数オブジェクトのコピーを返す
    // これがこのコードのポイントになる
    EvenCounter counter = std::for_each(numbers.begin(),
                                        numbers.end(),
                                        EvenCounter());
    
    // 例えば以下の様にも書き換えられる
    // 明示的にオブジェクトを作成しているのでわかりやすいかもしれない
    // EvenCounter initialCounter;
    // EvenCounter counter = std::for_each(numbers.begin(), numbers.end(), initialCounter);
    
    // C++17ではクラステンプレートの型推論が可能になったため、以下の様に書くこともできる
    // auto counter = std::for_each(numbers.begin(), numbers.end(), EvenCounter());
    
    std::cout << "Number of even numbers: " << counter.getCount() << std::endl;

    return 0;
}


