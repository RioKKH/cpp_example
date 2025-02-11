#pragma once
#include <string>
#include <unordered_map>

class ParameterManager {
private:
    ParameterManager() {} // プライベートコンストラクタ
    ParameterManager(const ParameterManager&) = delete; // コピーコンストラクタを禁止
    ParameterManager& operator=(const ParameterManager&) = delete; // 代入演算子を禁止

    std::unordered_map<std::string, std::string> parameters;

public:
    static ParameterManager& getInstance() {
        static ParameterManager instance;
        return instance;
    }

    void setParameter(const std::string& key, const std::string& value) {
        parameters[key] = value;
    }

    std::string getParameter(const std::string& key) const {
        auto it = parameters.find(key);
        return (it != parameters.end()) ? it->second : "";
    }
};
