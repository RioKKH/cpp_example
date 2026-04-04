#include <iostream>
#include <memory>
#include <cstdint>

class ImageBuffer
{
private:
    int w_, h_;
    // make_unique<uint8_t[]>(n)はゼロ初期化されたn要素の配列を確保する
    // スコープを抜けると自動解法される。delete[]を書く必要が無い。
    std::unique_ptr<uint8_t[]> data_;

public:
    ImageBuffer(int w, int h)
        : data_(std::make_unique<uint8_t[]>(w * h)), w_(w), h_(h) {}

    // constメンバ関数は「このメンバ関数内でthisのメンバ変数を変更しない」
    // 事をコンパイラに保証するもの
    int width() const { return w_; }
    int height() const { return h_; }
    int size() const { return w_ * h_; }
};

int main()
{
    int w, h;
    std::cin >> w >> h;
    ImageBuffer img(w, h);
    std::cout << img.width() << " " << img.height() << " " << img.size() << std::endl;
}
