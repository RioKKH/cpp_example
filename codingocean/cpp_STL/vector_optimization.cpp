#include <iostream>
#include <vector>
using namespace std;

struct POS {
    int x, y;
    // デフォルトコンストラクタ
    POS() : x(0), y(0)
    {
        cout << "initialized(" << x << ", " << y << ")" << endl;
    }
    // 変換コンストラクタ
    POS(int x, int y) : x(x), y(y)
    {
        cout << "converted(" << x << ", " << y << ")" << endl;
    }
    // コピーコンストラクタ
    POS(const POS& pos) : x(pos.x), y(pos.y)
    {
        cout << "copied(" << x << ", " << y << ")" << endl;
    }
};

ostream& operator<<(ostream& os, const POS& pos)
{
    return os << pos.x << ", " << pos.y;
}

int main()
{
    // // デフォルトコンストラクタ
    // POS pos1;
    // // 変換コンストラクタ
    // POS pos2 = {1, 1};
    // // コピーコンストラクタ
    // POS pos3 = pos2;

    // 要素数を変更できる配列
    vector<POS> data;
    // 予約しておくと要素数が増えても再確保が少なくて済む
    data.reserve(3);
    // お尻に要素を追加
    for (int i = 1; i <= 3; i++)
    {
        // data.push_back({i, i * 10});
        // 一時オブジェクトを作る必要がないので、中括弧を使わない
        data.emplace_back(i, i * 10);
        // 要素数と容量の表示。容量は要素数が増えると倍々で増える
        // cout << data.size() << " " << data.capacity() << endl;
    }
    // 全要素の表示
    for (auto it = data.begin(); it != data.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 途中に追加
    auto it = data.begin();
    // auto it = data.begin() + 2; // ２番目に追加する場合
    // data.insert(it, {0, 0});
    // 一時オブジェクトを作る必要がないので、中括弧を使わない
    data.emplace(it, 0, 0); 
    for (auto it = data.begin(); it != data.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
