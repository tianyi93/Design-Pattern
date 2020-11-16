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

struct LargeObject{
    LargeObject(){
        std::cout<<"LargeObject default constructor called"<<std::endl;
    }
    LargeObject(std::string const& content):content_(content){
        std::cout<<"LargeObject default constructor called"<<std::endl;
    }
    LargeObject(LargeObject const& l):content_(l.content_){
        std::cout<<"LargeObject copy constructor called"<<std::endl;
    }
    LargeObject(LargeObject&& l):content_(l.content_){
        std::cout<<"LargeObject move constructor called"<<std::endl;
    }
    LargeObject& operator=(LargeObject const& other){
        content_ = other.content_;
        std::cout<<"LargeObject operator= assignment  called"<<std::endl;
        return *this;
    }
    LargeObject& operator=(LargeObject && other){
        content_ = std::move(other.content_);
        std::cout<<"LargeObject operator= move assignment called"<<std::endl;
        return *this;
    }
    std::string to_string() const{
        return content_;
    }
private:
    std::string content_;
};

struct ConcretePrototype1{
    ConcretePrototype1(){
        std::cout<<"default ConcretePrototype1 constructor called"<<std::endl;
    }
    ConcretePrototype1(std::string const& prototypeName, LargeObject const& rarelyChangedField):
    prototypeName_(prototypeName), rarelyChangedField_(rarelyChangedField){
        std::cout<<"ConcretePrototype1 constructor called"<<std::endl;
    }
    ConcretePrototype1(ConcretePrototype1 const& concretePrototype1):
    prototypeName_(concretePrototype1.prototypeName_), rarelyChangedField_(concretePrototype1.rarelyChangedField_){
        std::cout<<"ConcretePrototype1 copy constructor called"<<std::endl;
    }
    ConcretePrototype1& operator=(ConcretePrototype1 const& other){
        std::cout<<"ConcretePrototype2 operator = copy constructor called"<<std::endl;
        prototypeName_ = other.prototypeName_;
        rarelyChangedField_ = other.rarelyChangedField_;
        return *this;
    }
    ConcretePrototype1 clone() const{
        return ConcretePrototype1(*this);
    }
    void print() const{
        std::cout<<"Printing ConcretePrototype1: ";
        std::cout << "prototypeName : " << prototypeName_ << ", rarelyChangedField : " << rarelyChangedField_.to_string() << std::endl;
    }
    std::string prototypeName_;
    LargeObject rarelyChangedField_;
};

struct ConcretePrototype2{
    ConcretePrototype2() {
        std::cout<<"default ConcretePrototype2 constructor called"<<std::endl;
    }
    ConcretePrototype2(std::string const& prototypeName, std::string const& rarelyChangedField){
        std::cout<<"ConcretePrototype2 constructor called"<<std::endl;
        prototypeName_ = prototypeName;
        rarelyChangedField_ = rarelyChangedField;
    }
    ConcretePrototype2(ConcretePrototype2 const& concretePrototype2){
        std::cout<<"ConcretePrototype2 copy constructor called"<<std::endl;
        prototypeName_ = concretePrototype2.prototypeName_;
        rarelyChangedField_ = concretePrototype2.rarelyChangedField_;
    }
    ConcretePrototype2& operator=(ConcretePrototype2 const& other){
        std::cout<<"ConcretePrototype2 operator = copy constructor called"<<std::endl;
        prototypeName_ = other.prototypeName_;
        rarelyChangedField_ = other.rarelyChangedField_;
        return *this;
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
    Prototype(){
        std::cout<<"Prototype default constructor is called"<<std::endl;
    }
    Prototype(Prototype&& prototype){
        std::cout<<"Prototype move constructor is called"<<std::endl;
        self = std::move(prototype.self);
    }
    template<typename T>
    Prototype(T const& prototype){
        std::cout<<"Prototype template constructor is called"<<std::endl;
        self = std::unique_ptr<PrototypeConcept const>(new PrototypeModel<T>(prototype));
    }
    Prototype& operator=(Prototype&& rhs){
        std::cout<<"Prototype operator = move assignment operator is called"<<std::endl;
        self = std::move(rhs.self);
        return *this;
    }
    Prototype clone() const{
        Prototype p(self->clone());
        return std::move(p);
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
        PrototypeModel(){
            std::cout<<"PrototypeModel default constructor is called"<<std::endl;
        }
        PrototypeModel(T const& prototype):prototype_(prototype){
            std::cout<<"PrototypeModel constructor is called"<<std::endl;
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
        LargeObject l1("this field contains info rarely changes for ConcretePrototype1!");
        prototypes_[Type::PROTOTYPE_1] = ConcretePrototype1("ConcretePrototype1",
                                                                l1);
        prototypes_[Type::PROTOTYPE_2] = ConcretePrototype2("ConcretePrototype2 ",
                                                                "this field contains info rarely changes for ConcretePrototype2!");
    }
    Prototype cloneSavedPrototype(Type type){
        return prototypes_[type].clone();
    }
};


#endif //DESIGN_PATTERN_PROTOTYPE_H

