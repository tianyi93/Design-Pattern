//
// Created by Tianyi Zhang on 11/4/20.
//

#ifndef DESIGN_PATTERN_PROTOTYPE_H
#define DESIGN_PATTERN_PROTOTYPE_H
#include <string>
#include <iostream>
#include <map>
#include <memory>

enum Type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

struct Prototype{
    Prototype(std::string const& prototypeName, std::string const& rarelyChangedField):
            prototypeName_(prototypeName), rarelyChangedField_(rarelyChangedField){};
    virtual Prototype* clone() = 0;
    void setPrototypeName(std::string const& name){
        prototypeName_ = name;
    }
    virtual void print(){
        std::cout << "prototypeName : " << prototypeName_ << ", rarelyChangedField : " << rarelyChangedField_ << std::endl;
    }
    virtual ~Prototype(){}
protected:
    std::string prototypeName_;
    std::string rarelyChangedField_;
};

struct ConcretePrototype1 : public Prototype{
    ConcretePrototype1(std::string const& prototypeName, std::string const& rarelyChangedField):
            Prototype(prototypeName, rarelyChangedField){};
    Prototype* clone() override{
        return new ConcretePrototype1(*this);
    }
    void print() override{
        std::cout<<"Printing ConcretePrototype1: ";
        Prototype::print();
    }
};

struct ConcretePrototype2 : public Prototype{
    ConcretePrototype2(std::string const& prototypeName, std::string const& rarelyChangedField):
            Prototype(prototypeName, rarelyChangedField){};
    Prototype* clone() override{
        return new ConcretePrototype2(*this);
    }
    void print() override{
        std::cout<<"Printing ConcretePrototype2: ";
        Prototype::print();
    }
};

/**
 * In PrototypeFactory you have two concrete prototypes, one for each concrete
 * prototype class, so each time you want to create a bullet , you can use the
 * existing ones and clone those.
 */

class PrototypeFactory {
private:
    std::map<Type, Prototype *> prototypes_;

public:
    PrototypeFactory() {
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("ConcretePrototype1",
                                                                "this field contains info rarely changes for ConcretePrototype1!");
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("ConcretePrototype2 ",
                                                                "this field contains info rarely changes for ConcretePrototype2!");
    }
    ~PrototypeFactory() {
        delete prototypes_[Type::PROTOTYPE_1];
        delete prototypes_[Type::PROTOTYPE_2];
    }
    Prototype* clonePrototype(Type type){
        return prototypes_[type]->clone();
    }
};


#endif //DESIGN_PATTERN_PROTOTYPE_H
