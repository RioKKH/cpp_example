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
