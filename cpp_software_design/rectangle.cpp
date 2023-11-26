#include <iostream>
#include <cassert>

class Rectangle
{
public:
    virtual ~Rectangle() = default;

    int getWidth() const;
    int getHeight() const;

    // 純粋仮想関数とする
    virtual void setWidth(int) = 0;
    virtual void setHeight(int) = 0;
    virtual int getArea() const = 0;

protected:
    int width;
    int height;
};

int Rectangle::getWidth() const
{
    return this->width;
}

int Rectangle::getHeight() const
{
    return this->height;
}

class Square : public Rectangle
{
public:
    void setWidth(int) override;
    void setHeight(int) override;

    int getArea() const override;
};

void Square::setWidth(int width)
{
    this->width = width;
    this->height = width;
}

void Square::setHeight(int height)
{
    this->width = height;
    this->height = height;
}

int Square::getArea() const
{
    return this->width * this->height;
}

void transform(Rectangle& rectangle)
{
    rectangle.setWidth(7);
    std::cout << rectangle.getWidth() << std::endl;
    std::cout << rectangle.getHeight() << std::endl;

    rectangle.setHeight(4);
    std::cout << rectangle.getWidth() << std::endl;
    std::cout << rectangle.getHeight() << std::endl;

    assert(rectangle.getArea() == 28);
}

int main()
{
    Square s{};
    s.setWidth(6);
    transform(s);

    return EXIT_SUCCESS;
}
