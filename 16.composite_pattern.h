//
// Created by Tianyi Zhang on 3/4/21.
//

#ifndef DESIGN_PATTERN_16_COMPOSITE_PATTERN_H
#define DESIGN_PATTERN_16_COMPOSITE_PATTERN_H

#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <map>

//The composite Pattern allows you to compose objects into tree structures to represent part-whole hierarchies.
// Composite lets clients treat individual objects and compositions of objects uniformly
//make menu easier to extend

struct MenuComponent{
    MenuComponent(std::string const& name, double price): name_(name), price_(price){};
    MenuComponent(std::string const& name): name_(name){};
    void add(MenuComponent const& menuComponent){
        menuComponents_.push_back(menuComponent);
    }
    void print() const{
        if(!isLeaf()){
            std::cout<<"--------------------------"<<std::endl;
            std::cout<<name_<<std::endl;
            std::cout<<"--------------------------"<<std::endl;
        }else{
            std::cout<<name_<<","<<price_<<std::endl;
        }
        for(auto menuComponent : menuComponents_){
            menuComponent.print();
        }
    }
private:
    bool isLeaf() const{
        return menuComponents_.size() == 0;
    }
    std::vector<MenuComponent> menuComponents_;
    std::string name_;
    double price_;
};

struct Waitress{
    Waitress(MenuComponent const& menuComponent): menuComponent_(menuComponent) {}
    void printMenu(){
        menuComponent_.print();
    }
private:
    MenuComponent menuComponent_;
};

#endif //DESIGN_PATTERN_16_COMPOSITE_PATTERN_H
