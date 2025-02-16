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
    virtual std::unique_ptr<Product> createProduct() = 0;
    virtual ~Factory() = default;
};

class ConcreteFactoryA : public Factory {
public:
    std::unique_ptr<Product> createProduct() override {
        return std::make_unique<ConcreteProductA>();
    }
};

class ConcreteFactoryB : public Factory {
public:
    std::unique_ptr<Product> createProduct() override {
        return std::make_unique<ConcreteProductB>();
    }
};

int main() {
    std::unique_ptr<Factory> factoryA = std::make_unique<ConcreteFactoryA>();
    std::unique_ptr<Product> productA = factoryA->createProduct();
    if(productA) productA->show();

    std::unique_ptr<Factory> factoryB = std::make_unique<ConcreteFactoryB>();
    std::unique_ptr<Product> productB = factoryB->createProduct();
    if(productB) productB->show();

    return 0;
}

// Output:
// ConcreteProductA Created
// ConcreteProductB Created