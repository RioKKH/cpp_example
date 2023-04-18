#include <iostream>
#include <exception>

class MyException : public std::exception
{
private:
    const char* message;

public:
    const char* what() const noexcept override;
};

const char* MyException::what() const noexcept
{
    return "MyException";
}

