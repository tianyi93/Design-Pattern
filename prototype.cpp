//
// Created by Tianyi Zhang on 11/4/20.
//

#include "prototype.h"
void foo(Prototype prototype){
    prototype.print();
    prototype.clone().print();
}
int main(){

    PrototypeFactory prototypeFactory;
    std::cout<<"------Prototype Factory built, start cloning------"<<std::endl;
    auto p1cloned = prototypeFactory.cloneSavedPrototype(Type::PROTOTYPE_1);
    p1cloned.print();
    prototypeFactory.cloneSavedPrototype(Type::PROTOTYPE_2).print();
    return 0;

}
/*
//printout
LargeObject default constructor called
LargeObject copy constructor called
ConcretePrototype1 constructor called
        Prototype template constructor is called
        LargeObject copy constructor called
        ConcretePrototype1 copy constructor called
        PrototypeModel constructor is called
        Prototype default constructor is called
        Prototype operator = move assignment operator is called
        ConcretePrototype2 constructor called
Prototype template constructor is called
        ConcretePrototype2 copy constructor called
        PrototypeModel constructor is called
        Prototype default constructor is called
        Prototype operator = move assignment operator is called
        LargeObject copy constructor called
        ConcretePrototype1 copy constructor called
        Prototype template constructor is called
        LargeObject copy constructor called
        ConcretePrototype1 copy constructor called
        PrototypeModel constructor is called
        Prototype move constructor is called
Printing ConcretePrototype1: prototypeName : ConcretePrototype1, rarelyChangedField : this field contains info rarely changes for ConcretePrototype1!
ConcretePrototype2 copy constructor called
Prototype template constructor is called
        ConcretePrototype2 copy constructor called
        PrototypeModel constructor is called
        Prototype move constructor is called
Printing ConcretePrototype2: prototypeName : ConcretePrototype2 , rarelyChangedField : this field contains info rarely changes for ConcretePrototype2!
*/