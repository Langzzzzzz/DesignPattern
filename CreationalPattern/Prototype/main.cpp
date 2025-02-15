#include <iostream>
#include <vector>
#include <memory>
#include <string>

// 抽象原型类 Prototype
class Prototype {
public:
    virtual ~Prototype() = default;
    virtual std::unique_ptr<Prototype> Clone() const = 0;
    virtual void Show() const = 0;
};

// 复杂对象的具体原型类 ComplexPrototype
class ComplexPrototype : public Prototype {
private:
    int basic_value;                // 基本类型 basic
    int* pointer_data;              // 需要深拷贝的指针数据 pointer
    std::unique_ptr<int> smart_ptr; // 智能指针（自动管理） smart pointer
    std::vector<int> numbers;       // 容器数据 vector
    std::string text;               // 字符串数据 string

public:
    // 构造函数 constructor 
    ComplexPrototype(int val, int ptr_val, int smart_ptr_val, std::vector<int> nums, std::string txt)
        : basic_value(val), 
          pointer_data(new int(ptr_val)), 
          smart_ptr(std::make_unique<int>(smart_ptr_val)), 
          numbers(std::move(nums)), 
          text(std::move(txt)) {}

    // 拷贝构造函数（深拷贝） copy constructor
    ComplexPrototype(const ComplexPrototype& other)
        : basic_value(other.basic_value+1),
          pointer_data(new int(*other.pointer_data)), // 深拷贝指针
          smart_ptr(std::make_unique<int>(*other.smart_ptr)), // 深拷贝智能指针
          numbers(other.numbers), // std::vector 默认拷贝是深拷贝 
          text(other.text) {} // std::string 默认拷贝是深拷贝

    // 赋值运算符重载（深拷贝）
    ComplexPrototype& operator=(const ComplexPrototype& other) {
        if (this == &other) return *this; // 避免自赋值

        basic_value = other.basic_value;
        *pointer_data = *other.pointer_data; // 深拷贝
        *smart_ptr = *other.smart_ptr; // 深拷贝智能指针
        numbers = other.numbers; // 深拷贝 vector
        text = other.text; // 深拷贝 string

        return *this;
    }

    // Clone 方法（创建深拷贝）
    std::unique_ptr<Prototype> Clone() const override {
        // 这实际上调用了 拷贝构造函数，创建了一个全新的对象，并返回它的 std::unique_ptr。
        // It actually calls the copy constructor, creates a new object, and returns its std::unique_ptr.
        return std::make_unique<ComplexPrototype>(*this);
    }

    // 显示对象信息
    // Show object information
    void Show() const override {
        std::cout << "Object Address: " << this << std::endl;
        std::cout << "Basic Value: " << basic_value << std::endl;
        std::cout << "Pointer Data: " << *pointer_data << std::endl;
        std::cout << "Smart Pointer Data: " << *smart_ptr << std::endl;
        std::cout << "Vector Data: ";
        for (int num : numbers) std::cout << num << " ";
        std::cout << "\nText: " << text << std::endl;

    }

    // 析构函数
    ~ComplexPrototype() {
        delete pointer_data;
    }
};

// 测试代码
int main() {
    // 创建原始对象
    ComplexPrototype original(10, 20, 30, {1, 2, 3, 4, 5}, "Hello World");

    // 克隆对象
    auto cloned = original.Clone();

    // 显示原始对象信息
    std::cout << "Original Object:" << std::endl;
    original.Show();

    // 显示克隆对象信息
    std::cout << "\nCloned Object:" << std::endl;
    cloned->Show();

    return 0;
}
