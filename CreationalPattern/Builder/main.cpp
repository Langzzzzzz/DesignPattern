#include <iostream>
#include <memory>
#include <string>

class Car {
    private:
        std::string brand;
        int horsePower;
        bool hasSunRoof;

    public:
        friend class CarBuilder;

        void show() {
            std::cout << "Car Brand: " << brand << ", Horse Power: " << horsePower << ", Sun Roof: " << (hasSunRoof ? "Yes" : "No")<< std::endl;
        }
};

class CarBuilder {
    protected:
        std::string brand;
        int horsePower = 100;
        bool hasSunRoof = false;
    
    public:
        virtual ~CarBuilder() = default;

        virtual CarBuilder& setBrand(std::string brand) {
            this->brand = brand;
            return *this;
        }

        virtual CarBuilder& setHorsePower(int horsePower) {
            this->horsePower = horsePower;
            return *this;
        }

        virtual CarBuilder& setSunRoof(bool hasSunRoof) {
            this->hasSunRoof = hasSunRoof;
            return *this;
        }

        virtual std::unique_ptr<Car> build() {
            std::unique_ptr<Car> car = std::make_unique<Car>();
            car->brand = this->brand;
            car->horsePower = this->horsePower;
            car->hasSunRoof = this->hasSunRoof;
            return car;
        }
};

class SportsCarBuilder : public CarBuilder {
    public:
        SportsCarBuilder() {
            this->brand = "Sports Car";
            this->horsePower = 300;
            this->hasSunRoof = true;
        }
};

class FamilyCarBuilder : public CarBuilder {
    public:
        FamilyCarBuilder() {
            this->brand = "Family Car";
            this->horsePower = 200;
            this->hasSunRoof = false;
        }
};


class CarDirector {
    private:
        CarBuilder* builder;

    public:
        CarDirector(CarBuilder* builder) : builder(builder) {}

        void setBuilder(CarBuilder* builder) {
            this->builder = builder;
        }

        std::unique_ptr<Car> constructSportsCar() {
            return builder->setBrand("Ferrari").setHorsePower(800).setSunRoof(true).build();
        }

        std::unique_ptr<Car> constructFamilyCar() {
            return builder->setBrand("Toyota").setHorsePower(200).setSunRoof(false).build();
        }

};

int main() {
    SportsCarBuilder sportsCarBuilder;
    FamilyCarBuilder familyCarBuilder;

    CarDirector director(&sportsCarBuilder);
    std::unique_ptr<Car> sportsCar = director.constructSportsCar();
    sportsCar->show();

    director.setBuilder(&familyCarBuilder);
    std::unique_ptr<Car> familyCar = director.constructFamilyCar();
    familyCar->show();

    return 0;
}