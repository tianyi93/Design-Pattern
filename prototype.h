//
// Created by Tianyi Zhang on 11/4/20.
//

#ifndef DESIGN_PATTERN_PROTOTYPE_H
#define DESIGN_PATTERN_PROTOTYPE_H
#include <string>
#include <iostream>
#include <map>

enum Type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

struct ConcretePrototype1{
    ConcretePrototype1() = default;
    ConcretePrototype1(std::string const& prototypeName, std::string const& rarelyChangedField){
        prototypeName_ = prototypeName;
        rarelyChangedField_ = rarelyChangedField;
    }
    ConcretePrototype1 clone() const{
        return ConcretePrototype1(*this);
    }
    void print() const{
        std::cout<<"Printing ConcretePrototype1: ";
        std::cout << "prototypeName : " << prototypeName_ << ", rarelyChangedField : " << rarelyChangedField_ << std::endl;
    }
    std::string prototypeName_;
    std::string rarelyChangedField_;
};

struct ConcretePrototype2{
    ConcretePrototype2() = default;
    ConcretePrototype2(std::string const& prototypeName, std::string const& rarelyChangedField){
        prototypeName_ = prototypeName;
        rarelyChangedField_ = rarelyChangedField;
    }
    ConcretePrototype2 clone() const{
        return ConcretePrototype2(*this);
    }
    void print() const{
        std::cout<<"Printing ConcretePrototype2: ";
        std::cout << "prototypeName : " << prototypeName_ << ", rarelyChangedField : " << rarelyChangedField_ << std::endl;
    }
    std::string prototypeName_;
    std::string rarelyChangedField_;
};

struct Prototype{
    Prototype() = default;
    template<typename T>
    Prototype(T const& prototype){
        self = std::unique_ptr<PrototypeConcept const>(new PrototypeModel<T>(prototype));
    }
    Prototype clone() const{
        return self->clone();
    }
    void print() const{
        self->print();
    }
private:
    struct PrototypeConcept{
        virtual Prototype clone() const= 0;
        virtual void print() const = 0;
        virtual ~PrototypeConcept(){};
    };

    template<typename T>
    struct PrototypeModel : public PrototypeConcept{
        PrototypeModel(T const& prototype){
            prototype_ = prototype;
        }
        Prototype clone() const override{
            return prototype_.clone();
        };
        void print() const override{
            prototype_.print();
        };
        ~PrototypeModel() override {}
        T prototype_;
    };
    std::unique_ptr<PrototypeConcept const> self;
};

/**
 * In PrototypeFactory you have two concrete prototypes, one for each concrete
 * prototype class, so each time you want to create a bullet , you can use the
 * existing ones and clone those.
 */

class PrototypeFactory {
private:
    std::map<Type, Prototype> prototypes_;

public:
    PrototypeFactory() {
        prototypes_[Type::PROTOTYPE_1] =  ConcretePrototype1("ConcretePrototype1",
                                                                "this field contains info rarely changes for ConcretePrototype1!");
        prototypes_[Type::PROTOTYPE_2] = ConcretePrototype2("ConcretePrototype2 ",
                                                                "this field contains info rarely changes for ConcretePrototype2!");
    }
    Prototype cloneSavedPrototype(Type type){
        return prototypes_[type].clone();
    }
};


#endif //DESIGN_PATTERN_PROTOTYPE_H

