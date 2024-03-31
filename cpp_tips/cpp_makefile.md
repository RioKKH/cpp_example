# Makefileの制御構造

## 条件分岐

```makefile
#ifeq 2つの引数が等しい場合に真となる
ifeq ($(CXX), g++)
	CXXFLAGS += -g
endif

#ifneq 2つの引数が等しくない場合に真となる
ifneq ($(RELEASE), 1)
	CXXFLAGS += -O0
else
	CXXFLAGS += -O3
endif

#ifdef 変数が定義されている場合に真となる
ifdef DEBUG
	CXXFLAGS += -DDEBUG
endif

#ifndef 変数が定義されていない場合に真となる
ifndef VERBOSE
	MAKEFLAGS += --silent
endif

```

## 繰り返し

```makefile
SRCS := main.cpp util.cpp parse.cpp
OBJS := $(SRCS:.cpp=.o)

# for
DIRS := src lib test
define make-goal
$1/%.o: %1/%.cpp
	$(CXX) $(CXXFLAGS) -c $$< -o $$@
endef
$(foreach dir,$(DIRS),$(eval $(call make-goal,$(dir))))
```

`$(foreach var,list,text)`は`list`の各要素を`var`に代入して`text`を評価する

`define`は複数行のテキストを定義する。`endef`で定義の終わりを示す

`$(eval $(call make-goal,$(dir)))`は`make-goal`の`$1`を`$(dir)`で置換してから評価する

`$$<`と`$$@`は`$<`と`$@`をエスケープするために使う。これは　`$`が特殊文字の為である。

この部分は、Makefileのパターンルールを定義しています。パターンルールは、ターゲットとそれに対応する依存ファイルのパターンを定義することで、複数のターゲットに対して同じルールを適用できます。

1. `$1`は、`define`ディレクティブで定義されたテキストの第1引数を表します。この例では、`$(foreach dir,$(DIRS),$(eval $(call make-goal,$(dir))))`の部分で、`$1`は`$(dir)`に置き換えられます。

2. `%`は、ターゲットと依存ファイルのパターンを表すワイルドカードです。例えば、`src/main.o`と`src/main.cpp`、`lib/util.o`と`lib/util.cpp`などがマッチします。

3. `$1/%.o`は、ターゲットのパターンを表します。`$1`が`src`の場合、`src/%.o`となり、`src`ディレクトリ内の`.o`ファイルにマッチします。

4. `$1/%.cpp`は、依存ファイルのパターンを表します。`$1`が`src`の場合、`src/%.cpp`となり、`src`ディレクトリ内の`.cpp`ファイルにマッチします。

5. ```
   $(CXX) $(CXXFLAGS) -c $< -o $@
   ```

   は、ターゲットを生成するためのレシピ（コマンド）です。

   - `$(CXX)`と`$(CXXFLAGS)`は、それぞれコンパイラとコンパイラフラグを表す変数です。
   - `-c`は、オブジェクトファイルを生成するためのオプションです。
   - `$<`は、依存ファイル（この場合は`.cpp`ファイル）を表します。
   - `-o`は、出力ファイル名を指定するオプションです。
   - `$@`は、ターゲット（この場合は`.o`ファイル）を表します。

つまり、この部分は、各ディレクトリ（`src`、`lib`、`test`）内の`.cpp`ファイルから`.o`ファイルを生成するためのルールを定義しています。`$(foreach)`と`$(eval)`を使って、各ディレクトリに対してこのルールが適用されます。

これにより、ディレクトリ構造が変更された場合でも、ルールを変更する必要がなくなります。

### \$evalと\$call

1. `$(eval)`は、Makefileの関数で、引数をMakefileのコードとして評価（実行）します。これにより、動的にルールやマクロを生成することができます。

```makefile
$(eval CXXFLAGS += -O3)
```

この例では、`$(eval)`は`CXXFLAGS += -O3`を評価し、`CXXFLAGS`変数に`-O3`を追加します。

1. `$(call)`は、Makefileの関数で、定義済みのマクロ（テキスト）を呼び出し、引数を渡すことができます。マクロは`define`ディレクティブで定義します。

```makefile
define my-macro # マクロを定義する
echo "Hello, $1!"
endef

target:
    $(call my-macro,World) # 定義済みマクロ(ここではmy-macro)を呼び出す
```

この例では、`my-macro`は`define`で定義されたマクロで、`$1`は第1引数を表します。`$(call my-macro,World)`は、`$1`を`World`に置換し、マクロを呼び出します。実行すると、`Hello, World!`が出力されます。

これらを組み合わせた例を見てみましょう：

```makefile
SRCS := main.cpp util.cpp parser.cpp
OBJS := $(SRCS:.cpp=.o)

DIRS := src lib test
define make-goal
$1/%.o: $1/%.cpp
    $(CXX) $(CXXFLAGS) -c $$< -o $$@
endef
$(foreach dir,$(DIRS),$(eval $(call make-goal,$(dir))))
```

ここでは、`make-goal`マクロが定義されています。`$(foreach dir,$(DIRS),$(eval $(call make-goal,$(dir))))`は、以下のような処理を行います：

1. `$(DIRS)`の各要素（`src`、`lib`、`test`）が`dir`変数に代入されます。
2. `$(call make-goal,$(dir))`で、`make-goal`マクロが呼び出され、`$1`が`$(dir)`に置換されます。
3. `$(eval)`で、置換後のマクロがMakefileのコードとして評価されます。

結果として、以下のようなルールが動的に生成されます：

```makefile
src/%.o: src/%.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
lib/%.o: lib/%.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
test/%.o: test/%.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
```

このように、`$(eval)`と`$(call)`を使うことで、動的にルールやマクロを生成し、コードの重複を減らすことができます。