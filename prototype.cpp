//
// Created by Tianyi Zhang on 11/4/20.
//

#include "prototype.h"

int main(){
    PrototypeFactory prototypeFactory;
    prototypeFactory.clonePrototype(Type::PROTOTYPE_1)->print();
    prototypeFactory.clonePrototype(Type::PROTOTYPE_2)->print();
    return 0;
}