# Step 1: `unique_ptr` で配列を持つクラスを作る

## 学習ポイント

- C++では `new[]` / `delete[]` の手動管理はバグの温床。`unique_ptr` に任せるのがRAIIの基本。
- `std::make_unique<uint8_t[]>(n)` はゼロ初期化された `n` 要素の配列を確保し、スコープを抜けると自動解放される。
- メンバ変数を変更しないメンバ関数には `const` を付ける。`const` 参照から呼べるようにするため。

## `const` メンバ関数とは

```cpp
int width() const { return w_; }
```

- 「この関数内でメンバ変数を変更しない」ことをコンパイラに保証する。
- `const ImageBuffer&` で受け取った参照からは、`const` メンバ関数しか呼べない。

```cpp
void printInfo(const ImageBuffer& img) {
    img.width();  // OK — const メンバ関数
    img.clear();  // エラー — 非const メンバ関数は呼べない
}
```

## 問題

`step1.cpp` の `// TODO` 部分に `size()` メンバ関数を追加せよ。

- 全ピクセル数 (`w_ * h_`) を返す `const` メンバ関数として実装する。

### 入出力

**入力:** 幅と高さ `W H`

**出力:** `W H size` を空白区切りで1行

### テスト例

| 入力 | 出力 |
|------|------|
| `4 3` | `4 3 12` |
| `1 1` | `1 1 1` |
| `1920 1080` | `1920 1080 2073600` |

### 実行方法

```bash
g++ -std=c++17 -o a.out step1.cpp
uv run oj test -c "./a.out" -d test/
```
