#include <iostream>
#include <type_traits>

template <typename T>
class vector2d
{
private:
    // type traits 型特性
    static_assert(std::is_signed<T>::value,
                  "Tは符号を扱える整数値である必要が有ります");
    T m_x;
    T m_y;

public:
    explicit vector2d(T x, T y) : m_x{x}, m_y{y}
    {
    }
    
    void show() const;
};

template <typename T>
void vector2d<T>::show() const
{
    std::cout << m_x << ", " << m_y << std::endl;
}

int main()
{
    vector2d<float> vf{2.0f, 3.0f};
    vector2d<int> vi{1, 2};
    vf.show();
    vi.show();
    // vector2d<unsigned int> vu;

    return 0;
}

