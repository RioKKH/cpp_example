#include <iostream>

/**
 * ビジターパターンとは、オブジェクトの操作をそのクラスから分離することで、
 * 新しい操作を追加するのを容易にするデザインパターンです。
 */

/// "Element" interface
class Element {
public:
    virtual ~Element() {}
    virtual void accept(class Visitor &v) = 0;
};

/// "ConcreteElement" classes
class This : public Element {
public:
    void accept(Visitor &v);
    std::string thiss() { return "This"; }
};

class That : public Element {
public:
    void accept(Visitor &v);
    std::string that() { return "That"; }
};


/// "Visitor" interface
class Visitor {
public:
    virtual ~Visitor() {}
    virtual void visit(This *e) = 0;
    virtual void visit(That *e) = 0;
};

/// "concreteVisitor" classes
class UpVisitor : public Visitor {
public:
    void visit(This *e) {
        std::cout << "do Up on " + e->thiss() << '\n';
    }
    void visit(That *e) {
        std::cout << "do Up on " + e->that() << '\n';
    }
};

class DownVisitor : public Visitor {
public:
    void visit(This *e) {
        std::cout << "do Down on " + e->thiss() << '\n';
    }
    void visit(That *e) {
        std::cout << "do Down on " + e->that() << '\n';
    }
};

/// Implement "accept" functions
void This::accept(Visitor &v) { v.visit(this); }
void That::accept(Visitor &v) { v.visit(this); }

int main() {
    This aThis;
    That aThat;

    UpVisitor up;
    DownVisitor down;

    aThis.accept(up);
    aThat.accept(up);

    aThis.accept(down);
    aThat.accept(down);
}

