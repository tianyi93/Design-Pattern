//
// Created by Tianyi Zhang on 1/3/21.
//

#ifndef DESIGN_PATTERN_12_DECORATOR_PATTERN_H
#define DESIGN_PATTERN_12_DECORATOR_PATTERN_H
#include <string>
#include <memory>

struct Beverage{
    virtual std::string getDescription(){
        return description;
    }
    virtual double cost() = 0;
    virtual ~Beverage(){}
protected:
    std::string description;
};

struct HouseBlend : public Beverage{
    HouseBlend(){
        description = "HouseBlend";
    }
    double cost() override{
        return 1.5;
    }
};

struct DarkRoast : public Beverage{
    DarkRoast(){
        description = "DarkRoast";
    }
    double cost() override{
        return 2.5;
    }
};

struct CondimentDecorator : public Beverage{
    virtual std::string getDescription()  = 0;

protected:
    std::shared_ptr<Beverage> beverage;
};

struct  Mocha : public CondimentDecorator{
    Mocha(std::shared_ptr<Beverage> beverage){
        this->beverage = beverage;
        this->description = "Mocha";
    }
    std::string getDescription() override{
        return beverage->getDescription() + "," + this->description;
    }
    double cost() override{
        return 0.5+beverage->cost();
    }
};

struct  Milk : public CondimentDecorator{
    Milk(std::shared_ptr<Beverage> beverage){
        this->beverage = beverage;
        this->description = "Milk";
    }
    std::string getDescription() override{
        return beverage->getDescription() + "," + this->description;
    }
    double cost() override{
        return 0.6+beverage->cost();
    }
};
#endif //DESIGN_PATTERN_12_DECORATOR_PATTERN_H
