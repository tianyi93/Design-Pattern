#ifndef DESIGN_PATTERN_FACTORY_UFO_H
#define DESIGN_PATTERN_FACTORY_UFO_H
#include <string>
#include <iostream>
#include <memory>

class UFO{
public:
    virtual void displayUFO() = 0;
    virtual void setName(std::string name) = 0;
    virtual void setSpeed(int speed) = 0;
};

class UFOImpl : public UFO{
public:
    void displayUFO() override{
        std::cout<<"name: "<<name<<" speed:"<<speed<<std::endl;
    }
    void setName(std::string name) override{
        this->name = name;
    }
    void setSpeed(int speed) override{
        this->speed = speed;
    }
private:
    std::string name;
    int speed;
};

class FakeUFO: public UFOImpl{
public:
    FakeUFO(){
        setName("fakeUFO");
        setSpeed(1);
    }
};

class RealUFO: public UFOImpl{
public:
    RealUFO(){
        setName("realUFO");
        setSpeed(100);
    }
};

class UFOFactory{
public:
    std::shared_ptr<UFO> makeUFO(std::string type){
        if(type == "F") {
              auto fakeUFO = std::shared_ptr<FakeUFO>(new FakeUFO());
              return fakeUFO;
        }
        else if(type == "R"){
            auto realUFO = std::shared_ptr<RealUFO>(new RealUFO());
            return realUFO;
        }
    }
};

#endif //DESIGN_PATTERN_FACTORY_UFO_H
