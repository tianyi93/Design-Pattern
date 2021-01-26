//
// Created by Tianyi Zhang on 11/16/20.
//

#ifndef DESIGN_PATTERN_6_ADAPTER_H
#define DESIGN_PATTERN_6_ADAPTER_H
#include <iostream>

struct IClient{
    virtual void print() = 0;
};


struct Adaptee{
    void specialPrint(){
        std::cout<<"Special print function in Adaptee"<<std::endl;
    }
};

struct Adapter : public IClient{
    void print() override{
        adaptee_.specialPrint();
    }

private:
    Adaptee adaptee_;
};


#endif //DESIGN_PATTERN_6_ADAPTER_H
