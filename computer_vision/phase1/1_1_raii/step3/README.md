# Step 3: コピー禁止とムーブ

## 学習ポイント

- 画像バッファのような大きなリソースを持つクラスは、意図しないコピーを防ぎムーブだけ許可するのが安全。
- `= delete` でコピーを禁止、`= default` でムーブを許可する。
- `std::move` は所有権を移すだけで、データのコピーは発生しない。

## コピー禁止・ムーブ許可の書き方

```cpp
class ImageBuffer {
    std::unique_ptr<uint8_t[]> data_;
    int w_, h_;
public:
    // コピー禁止
    ImageBuffer(const ImageBuffer&) = delete;
    ImageBuffer& operator=(const ImageBuffer&) = delete;

    // ムーブ許可
    ImageBuffer(ImageBuffer&&) = default;
    ImageBuffer& operator=(ImageBuffer&&) = default;
};
```

`unique_ptr` をメンバに持っていると、コピーはそもそもコンパイルエラーになる。
`= delete` は意図を明示するために書く。

## ムーブ後の状態

```cpp
ImageBuffer a(1920, 1080);
ImageBuffer b = std::move(a);   // a の中身が b に移る
// a.data_ は nullptr になっている（空）
// b にデータがある
```

ムーブ後のオブジェクトは「有効だが不定」な状態。`data_` が `nullptr` になることを利用して `empty()` 判定ができる。
中身が`nullptr`ならば`false`, 有効なポインタならば`true`になる。

```cpp
std::unique_ptr<int> p;
if (p) { /* 入らない */}
if (!p) { /* 入る */ }
```

## 問題

`step3.cpp` の2箇所の `// TODO` を実装せよ。

1. コピーコンストラクタとコピー代入演算子を `delete`
2. ムーブコンストラクタとムーブ代入演算子を `default`

### 入出力

**入力:**
```
W H N
set x1 y1 v1
...
get x y
...
```

前半で `set` によりピクセルを書き込み、ムーブ後に `get` でムーブ先からデータを読み出す。

**出力:**
- ムーブ元が空なら `MOVED`
- ムーブ先の `width height`
- 各 `get` の結果

### テスト例

| 入力 | 出力 |
|------|------|
| `4 3 2` / `set 1 2 255` / `set 0 0 128` / `get 1 2` / `get 0 0` | `MOVED` / `4 3` / `255` / `128` |
| `2 2 0` / `get 0 0` / `get 1 1` | `MOVED` / `2 2` / `0` / `0` |

### 実行方法

```bash
g++ -std=c++17 -o a.out step3.cpp
uv run oj test -c "./a.out" -d test/
```
