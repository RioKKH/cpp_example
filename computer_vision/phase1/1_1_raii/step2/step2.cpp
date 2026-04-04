#include <iostream>
#include <memory>
#include <string>
#include <cstdint>
#include <stdexcept>

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

    // 返された値を通じて元のデータを直接読み書きできる
    uint8_t &at(int x, int y)
    {
        if (x < 0 || x >= w_ || y < 0 || y >= h_)
        {
            throw std::out_of_range("at: index out of range");
        }
        return data_[y * w_ + x];
    }
};

int main()
{
    int w, h, n;
    std::cin >> w >> h >> n;
    ImageBuffer img(w, h);

    for (int i = 0; i < n; ++i)
    {
        std::string op;
        int x, y;
        std::cin >> op >> x >> y;
        if (op == "set")
        {
            int v;
            std::cin >> v;
            try
            {
                img.at(x, y) = static_cast<uint8_t>(v);
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "ERR" << std::endl;
            }
        }
        else
        {
            try
            {
                std::cout << static_cast<int>(img.at(x, y)) << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "ERR" << std::endl;
            }
        }
    }
    return 0;
}
