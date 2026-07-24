#include <functional>
#include <iostream>

// こちらがコールバック関数を呼び出す側でライブラリに相当する
// std::function<void(int)> : intを1つ受け取りvoidを返す呼び出し可能な何か
// &cb : 参照で受ける
// ひきすうとしてわたしているのはラムダ⇒std::functionではない！
// 暗黙変換 std::function<void<int)>の一時オブジェクトが生成される。
// そしてC++のルール上、一時オブジェクトを束縛できるのはconst参照だけ
void capture(const std::function<void(int)> &cb) {
  for (int i = 0; i < 3; ++i) {
    cb(i);
  }
}

int main() {
  int total = 0;
  // [&total](int id) {...} がコールバック関数に当たる
  capture([&total](int id) {
    total += id;
    std::cout << "frame " << id << '\n';
  });
  std::cout << "total=" << total << '\n';
}
