#include <iostream>
#include <vector>
#include <memory>

/**
 * Widgetの集合を一つのグループとして扱うためのCompositeパターンの例
 * この例では、GUIのウィジェットを表すWidgetクラスを定義し、
 * その中でButtonやTextFieldなどの具象クラスを定義しています。
 * また、これらのウィジェットをまとめるためのCompositeWidgetクラスを定義しています。
 * CompositeWidgetクラスは、Widgetクラスを継承しており、
 * その中で子ウィジェットを保持するためのコンテナを持っています。
 * このように、Compositeパターンを使うことで、
 * 複数のオブジェクトを一つのオブジェクトとして扱うことができます。
 */

// 抽象コンポーネントクラス
class Widget {
public:
    // 純粋仮想関数。宣言時に "= 0" を付けることで、
    // この関数が純粋仮想関数であると明示することが出来る
    // 純粋仮想関数を一つでも持つクラスは抽象クラスとなり、
    // そのクラスのインスタンスを生成することができない。
    // これにより、他のクラスが基底クラスの関数の実装を提供する事を
    // 強制する事が出来る。
    virtual void draw() = 0; // 各コンポーネントが持つべき共通の機能
    virtual ~Widget() {}
};

// 葉コンポーネントクラス1
class Button : public Widget {
public:
    // 多態性を利用して、drawメソッドをオーバーライド
    void draw() override {
        std::cout << "Drawing a Button." << std::endl;
    }
};

// 葉コンポーネントクラス2
class TextField : public Widget {
public:
    // 多態性を利用して、drawメソッドをオーバーライド
    void draw() override {
        std::cout << "Drawing a TextField." << std::endl;
    }
};

// コンポジットクラス
class CompositeWidget : public Widget {
private:
    std::vector<std::shared_ptr<Widget>> children;
public:
    void add(std::shared_ptr<Widget> child) {
        children.push_back(child);
    }

    void draw() override {
        std::cout << "CompositeWidget that contains:" << std::endl;
        for (const auto& child : children) {
            child->draw(); // 子コンポーネントのdrawメソッドを呼び出す
        }
    }
};

int main() {
    std::shared_ptr<Widget> button = std::make_shared<Button>();
    std::shared_ptr<Widget> textfield = std::make_shared<TextField>();
    std::shared_ptr<CompositeWidget> form = std::make_shared<CompositeWidget>();

    form->add(button);
    form->add(textfield);

    // フォーム全体を描画する
    form->draw(); // "Composite Widget that contains:"
                  // と表示された後、各子ウィジェットが描画されます。
    return 0;
}






