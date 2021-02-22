//
// Created by Tianyi Zhang on 2/21/21.
//

#ifndef DESIGN_PATTERN_14_TEMPLATE_METHOD_H
#define DESIGN_PATTERN_14_TEMPLATE_METHOD_H

#include <iostream>

struct CaffeineBeverage{
    void prepareRecipe(){
        boilWater();
        brew();
        pourInCup();
        if(withCondiments()) {
            addCondiments();
        }
    }
private:
    void boilWater(){
        std::cout<<"boiling water"<<std::endl;
    }
    void pourInCup(){
        std::cout<<"pour into cup"<<std::endl;
    }
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
    virtual bool withCondiments(){
        return true;
    };
};

struct Tea : public CaffeineBeverage{
private:
    void brew() override{
        std::cout<<"steeping the tea"<<std::endl;
    }
    void addCondiments() override{
        std::cout<<"Adding Lemon"<<std::endl;
    }
    bool withCondiments() override{
        std::cout<<"would you like to add lemon in tea?(yes/no)"<<std::endl;
        std::string choice;
        std::cin>>choice;
        if(*choice.begin() == 'y')
            return true;
        else if(*choice.begin() == 'n')
            return false;
        else
            std::cout<<"not a valid option, use default true"<<std::endl;
        return true;
    }
};

struct Coffee : public CaffeineBeverage{
private:
    void brew() override{
        std::cout<<"Dripping Coffee through filter"<<std::endl;
    }
    void addCondiments() override{
        std::cout<<"Adding Sugar and Milk"<<std::endl;
    }
};

#endif //DESIGN_PATTERN_14_TEMPLATE_METHOD_H
