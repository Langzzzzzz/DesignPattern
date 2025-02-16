#include <iostream>
#include <string>
#include <memory>

class Product {
public:
    virtual void show() = 0;
    virtual ~Product() = default;
};

class ConcreteProductA : public Product {
public:
    void show() override {
        std::cout << "ConcreteProductA Created" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void show() override {
        std::cout << "ConcreteProductB Created" << std::endl;
    }
};

class Factory {
public:
    std::unique_ptr<Product> createProduct(std::string type) {
        if (type == "A") {
            return std::make_unique<ConcreteProductA>();
        } else if (type == "B") {
            return std::make_unique<ConcreteProductB>();
        } else {
            return nullptr;
        }
    }
};

int main() {
    Factory factory;
    std::unique_ptr<Product> productA = factory.createProduct("A");
    if(productA) productA->show();

    std::unique_ptr<Product> productB = factory.createProduct("B");
    if(productB) productB->show();

    return 0;
}