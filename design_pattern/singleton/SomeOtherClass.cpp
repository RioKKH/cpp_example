#include "ParameterManager.hpp"
#include <iostream>

class SomeOtherClass {
private:

public:
    void doSomething() {
        auto& paramManager = ParameterManager::getInstance();

        // パラメータの設定
        paramManager.setParameter("key1", "value1");

        // パラメータの取得
        std::string value = paramManager.getParameter("key1");
        std::cout << "Value for key1: " << value << std::endl;
    }
};

int main() {
    SomeOtherClass soc;
    soc.doSomething();
    return 0;
}




