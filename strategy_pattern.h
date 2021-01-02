//
// Created by Tianyi Zhang on 1/2/21.
//

#ifndef DESIGN_PATTERN_STRATEGY_PATTERN_H
#define DESIGN_PATTERN_STRATEGY_PATTERN_H
#include <string>
#include <iostream>
#include <memory>

struct FlyBehavior{
    virtual void fly() = 0;
    virtual ~FlyBehavior(){};
};

struct QuackBehavior{
    virtual void quack() = 0;
    virtual ~QuackBehavior(){};
};

struct Duck{
public:
    virtual void display() = 0;
    void performQuack(){
        if(quackBehavior != nullptr)
            quackBehavior->quack();
        else
            throw("quack behavior not set");
    }
    void performFly(){
        if(flyBehavior != nullptr)
            flyBehavior->fly();
        else
            throw("fly behavior not set");
    }
    void setQuackBehavior(std::shared_ptr<QuackBehavior> quackBehavior){
        this->quackBehavior = quackBehavior;
    }
    void setFlyBehavior(std::shared_ptr<FlyBehavior> flyBehavior){
        this->flyBehavior = flyBehavior;
    }
    virtual ~Duck(){};
private:
    std::shared_ptr<FlyBehavior> flyBehavior;
    std::shared_ptr<QuackBehavior> quackBehavior;
};

struct FlyWithWings:FlyBehavior{
    void fly() override{
        std::cout<<"duck is flying"<<std::endl;
    }
};

struct FlyNoWay:FlyBehavior{
    void fly() override{
        std::cout<<"duck cannot fly"<<std::endl;
    }
};

struct Quack : QuackBehavior{
    void quack() override{
        std::cout<<"quacking"<<std::endl;
    }
};

struct MuteQuack : QuackBehavior{
    void quack() override{
        std::cout<<"mute quacking"<<std::endl;
    }
};

struct RealDuck : Duck{
    void display() override{
        std::cout<<"This is a real duck"<<std::endl;
    }
};

struct FakeDuck : Duck{
    void display() override{
        std::cout<<"This is a fake duck"<<std::endl;
    }
};
#endif //DESIGN_PATTERN_STRATEGY_PATTERN_H
