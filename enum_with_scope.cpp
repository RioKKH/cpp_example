#include <iostream>

int main(int argc, char const* argv[])
{
    enum class choice1 {
        ROCK,
        SCISSORS,
        PAPER
    };

    enum struct choise2 {
        ROCK,
        SCISSORS,
        PAPER
    };

    choice1 x = choice1::ROCK;
    std::cout << (x == choice1::ROCK ? "ROCK" : "Other than ROCK") << std::endl;

    enum choice3 {
        rock,
        scissors,
        paper
    };

    choice3 y = rock;
    std::cout << y << std::endl; // output is 0. It means rock.
    // int rock = 1; // error. variable name is duplicated.
}
