# C++

## virtualについて

### 解説

C++における`virtual`キーワードの使用は、主にポリモーフィズム（多態性）という概念と関連しています。このキーワードがメンバ関数に適用されると、その関数は「仮想関数」となり、サブクラスでオーバーライド（上書き）されることができます。具体的には、以下のような役割を持っています：

1. **デストラクタにおける`virtual`の使用**:
   - ベースクラスのデストラクタに`virtual`を付けると、派生クラスのオブジェクトがベースクラスのポインタや参照を通じて削除される場合に、適切なデストラクタ（派生クラスのデストラクタ）が呼び出されます。
   - これにより、リソースの正しい解放やクリーンアップが保証されます。
   - もしベースクラスのデストラクタが`virtual`でない場合、ベースクラスのポインタを介して派生クラスのオブジェクトを削除すると、未定義動作が発生し、リソース漏れや他の問題が起こる可能性があります。
2. **メンバ関数における`virtual`の使用**:
   - `virtual`を使って宣言されたメンバ関数は、派生クラスでオーバーライドできます。
   - ベースクラスのポインタや参照を通じて派生クラスのオブジェクトを扱う際、ポリモーフィックな動作を可能にします。つまり、実行時にオブジェクトの実際の型に基づいて、適切なメンバ関数（ベースクラスか派生クラスの実装）が呼び出されます。
   - この機能は「動的ディスパッチ」または「実行時バインディング」として知られており、オブジェクト指向プログラミングにおいて重要な役割を果たします。

例えば、あなたのクラス`Document`において、`exportJson`や`serialize`メソッドに`virtual`が付与されているのは、これらのメソッドが派生クラスで特化された動作を持つことが想定されているためです。これにより、`Document`型のポインタや参照を通じて派生クラスのオブジェクトを扱う際、適切なメソッドの実装が動的に選択されます。

### コード例

```C++
#include <iostream>
#include <string>

// Base class
class Document {
public:
    virtual ~Document() {
        std::cout << "Destroying Document" << std::endl;
    }

    virtual void exportJson() const {
        std::cout << "Exporting Docuemt as JSON" << std::endl;
    }

    virtual void serialize() const {
        std::cout << "Serializing Document" << std::endl;
    }
};

// Derived class
class TextDocument : public Document {
public:
    ~TextDocument() override {
        std::cout << "Destroying TextDocument" << std::endl;
    }

    void exportJson() const override {
        std::cout << "Exporting TextDocument as JSON" << std::endl;
    }

    void serialize() const override {
        std::cout << "Serializing TextDocument" << std::endl;
    }
};


int main() {
    Document* doc = new TextDocument();
    doc->exportJson();
    doc->serialize();
    delete doc; // This will call the destructor of TextDocument, then Document.
    return 0;
}

```

