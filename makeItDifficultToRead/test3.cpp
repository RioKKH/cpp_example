#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 文字列を小文字に変換する
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// 文字列を大文字に変換する
string toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// ファイルを読み込む
vector<string> readFile(string fileName) {
    vector<string> lines;
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    return lines;
}

// ファイルに書き込む
void writeFile(vector<string> lines, string fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (string line : lines) {
            file << line << endl;
        }
        file.close();
    }
}

// 文字列をルールに従って置換する
string replace(string str) {
    bool isFirstChar = true;
    string newStr = "";
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            if (isFirstChar) {
                newStr += str[i];
            } else {
                if (isupper(str[i])) {
                    newStr += "X";
                } else {
                    newStr += "x";
                }
            }
            isFirstChar = false;
        } else {
            newStr += str[i];
            isFirstChar = true;
        }
    }
    return newStr;
}

// ルールに従ってファイルの内容を置換する
vector<string> replaceFile(vector<string> lines) {
    vector<string> newLines;
    for (string line : lines) {
        newLines.push_back(replace(line));
    }
    return newLines;
}

int main() {
    // 入力ファイルの読み込み
    vector<string> lines = readFile("input.txt");

    // ファイルの内容を置換する
    vector<string> newLines = replaceFile(lines);

    // 置換後のファイルを出力する
    writeFile(newLines, "output.txt");

    return 0;
}
