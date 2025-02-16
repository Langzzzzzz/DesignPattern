#include <iostream>
#include <memory>

class Button {
public:
    virtual void Click() const = 0;
    virtual ~Button() = default;
};

class Checkbox {
public:
    virtual void Check() const = 0;
    virtual ~Checkbox() = default;
};

class WindowsButton : public Button {
public:
    void Click() const override { std::cout << "Windows Button Clicked.\n"; }
};

class WindowsCheckbox : public Checkbox {
public:
    void Check() const override { std::cout << "Windows Checkbox Checked.\n"; }
};

class MacButton : public Button {
public:
    void Click() const override { std::cout << "Mac Button Clicked.\n"; }
};

class MacCheckbox : public Checkbox {
public:
    void Check() const override { std::cout << "Mac Checkbox Checked.\n"; }
};

class GUIFactory {
public:
    virtual std::unique_ptr<Button> CreateButton() const = 0;
    virtual std::unique_ptr<Checkbox> CreateCheckbox() const = 0;
    virtual ~GUIFactory() = default;
};

class WindowsFactory : public GUIFactory {
public:
    std::unique_ptr<Button> CreateButton() const override {
        return std::make_unique<WindowsButton>();
    }
    std::unique_ptr<Checkbox> CreateCheckbox() const override {
        return std::make_unique<WindowsCheckbox>();
    }
};

class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> CreateButton() const override {
        return std::make_unique<MacButton>();
    }
    std::unique_ptr<Checkbox> CreateCheckbox() const override {
        return std::make_unique<MacCheckbox>();
    }
};

int main() {
    std::unique_ptr<GUIFactory> factory = std::make_unique<WindowsFactory>();
    std::unique_ptr<Button> button = factory->CreateButton();
    button->Click();
    std::unique_ptr<Checkbox> checkbox = factory->CreateCheckbox();
    checkbox->Check();

    factory = std::make_unique<MacFactory>();
    button = factory->CreateButton();
    button->Click();
    checkbox = factory->CreateCheckbox();
    checkbox->Check();

    return 0;
}