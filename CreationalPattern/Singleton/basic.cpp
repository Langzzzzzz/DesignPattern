#include <iostream>
#include <string>
#include <thread>

class Singleton
{
    protected:
        Singleton(const std::string value) : value_(value) {}

        static Singleton* singleton_;

        std::string value_;
    public:
        Singleton(Singleton &other) = delete;
        void operator=(const Singleton &) = delete;

        static Singleton* getInstance(const std::string& value);
        std::string value() const { return value_; }

};

Singleton* Singleton::singleton_ = nullptr;

Singleton* Singleton::getInstance(const std::string& value)
{
    if (singleton_ == nullptr)
    {
        singleton_ = new Singleton(value);
    }
    return singleton_;
}

void clientCode()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("FOO");
    std::cout << singleton->value() << std::endl;
}

void clientCode2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("BAR");
    std::cout << singleton->value() << std::endl;
}

int main()
{
    std::cout << "If you see the same value, then singleton was reused (yay!)\n"
              << "If you see different values, then 2 singletons were created (booo!!)\n\n"
              << "RESULT:\n";
    std::thread t1(clientCode);
    std::thread t2(clientCode2);
    t1.join();
    t2.join();
    return 0;
}

