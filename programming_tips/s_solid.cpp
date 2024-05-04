// S - Single Responsibility principle (単一責任の原則)
#include <iostream>

class Logger {
public:
    void log(const std::string &message) {
        std::cout << "Log: " << message << std::endl;
    }
};

class DataProcessor {
private:
    Logger logger;

public:
    void process(const std::string &data) {
        logger.log("Data processed");
    }
};



