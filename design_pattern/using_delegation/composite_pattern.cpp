#include <iostream>
#include <vector>
#include <memory>

/**
 * オブジェクトを木構造で表現し、個々のオブジェクトとオブジェクトの集まりを
 * クライアントが同じように扱えるようにするパターン。
 * 例えば、ファイルシステムのディレクトリ構造を表現する際に使用される。
 * このパターンでは、コンポーネント(LeafとNode)が共通のインターフェースを持ち、
 * ノードは子コンポーネントへの操作を子コンポーネントに委譲する。
 */

/**
 * 全ての構成要素の共通インターフェース
 */
class Component {
public:
    virtual void operation() = 0;
    virtual ~Component() {}
};

/**
 * Componentインターフェースを実装するクラス
 * これ以上分割されない「葉」の要素を表す。
 * Leafクラスは通常、実際の操作を行う。
 */
class Leaf : public Component {
public:
    void operation() override {
        std::cout << "Leaf operation" << std::endl;
    }
};

/**
 * Componentインターフェースを実装するクラスだが、他のComponentオブジェクトを
 * 子として保持できるクラス。Compositeクラスは子オブジェクトの集合を管理し、
 * Componentインターフェースで定義されている操作を子オブジェクトに対して
 * 再帰的に呼び出す。
 */
class Composite : public Component {
private:
    std::vector<std::shared_ptr<Component>> children;
public:
    void add(std::shared_ptr<Component> component) {
        children.push_back(component);
    }

    void operation() override {
        std::cout << "Composite operation" << std::endl;
        for (auto& child : children) {
            child->operation();
        }
    }
};

int main() {
    std::shared_ptr<Component> leaf1 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf2 = std::make_shared<Leaf>();
    std::shared_ptr<Composite> root = std::make_shared<Composite>();

    root->add(leaf1);
    root->add(leaf2);
    root->operation();
    return 0;
}

