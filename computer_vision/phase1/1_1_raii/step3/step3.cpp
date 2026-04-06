#include <iostream>
#include <memory>
#include <strings>
#include <cstdint>
#include <stdexcept>

class ImageBuffer
{
private:
    std::unique_ptr<uint8_t[]> data_;
    int w_, h_;

public:
    ImageBuffer(int w, int h)
        : data_(std::make_unique<uint8_t[]>(w * h)), w_(w), h_(h) {}

    // TODO: コピーを禁止してください。
    // (コピーコンストラクタとコピー代入演算子をdelete)

    // TODO: ムーブを許可してください。
    // (ムーブコンストラクタとムーブ代入演算子をdefault)

    int width() const { return w_; }
    int height() const { return h_; }
    int size() const { return w_ * h_; }

    uint8_t &at(int x, int y)
    {
        if (x < 0 || x >= w_ || y < 0 || y >= h_)
        {
            throw std::out_of_range("at: index out of range");
        }
        return data_[y * w_ + x];
    }

    // ムーブ後に空になったか判定する
    // ムーブ後のdata_がnullptrになることを利用して判定が可能
    bool empty() const { return !data_; }
};

// ムーブで所有権を受け取る関数
ImageBuffer transferOwnership(ImageBuffer &&src)
{
    return std::move(src);
}

int main()
{
    int w, h, n;
    std::cin >> w >> h >> n;
    ImageBuffer img(w, h);

    // ピクセル操作
    for (int i = 0; i < n; ++i)
    {
        std::string op;
        int x, y;
        std::cin >> op >> x >> y;
        if (op == "set")
        {
            int v; // そのピクセルの値 (value)
            std::cin >> v;
            img.at(x, y) = static_cast<uint8_t>(v);
        }
    }

    // ムーブで所有権を移す
}
