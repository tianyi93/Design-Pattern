//
// Created by Tianyi Zhang on 2/22/21.
//

#ifndef DESIGN_PATTERN_15_ITERATOR_PATTERN_H
#define DESIGN_PATTERN_15_ITERATOR_PATTERN_H
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

//hash function for MenuItem
struct MenuItem;

template <>
struct std::hash<MenuItem>
{
    std::size_t operator()(const MenuItem& k) const;
};

struct MenuItem{
    MenuItem(std::string const& name, double price): name_(name), price_(price){};
    void printItem(){
        std::cout<<name_<<","<<price_<<std::endl;
    }
    bool operator==(const MenuItem &other) const{
        return (name_ == other.name_&& price_ == other.price_);
    }
private:
    std::string name_;
    double price_;
    friend class std::hash<MenuItem>;
};

std::size_t std::hash<MenuItem>::operator()(const MenuItem& k) const
{

    // Compute individual hash values for first,
    // second and third and combine them using XOR
    // and bit shifting:

    return ((hash<string>()(k.name_)
             ^ (hash<double>()(k.price_) << 1)) >> 1);
}

struct MenuItemIterator{
    virtual bool hasNext() = 0;
    virtual void next() = 0;
    virtual MenuItem getMenuItem() = 0;
};

struct BreakfastMenuIterator: public MenuItemIterator{
    BreakfastMenuIterator( std::vector<MenuItem> const& menuItems) : menuItems_(menuItems){
        curIterator_ = menuItems_.begin();
    }
    bool hasNext() override{
        if(curIterator_ == menuItems_.end())
            return false;
        else
            return true;
    }
    void next() override{
        curIterator_ = ++curIterator_;
    }
    MenuItem getMenuItem() override{
        return *curIterator_;
    }
private:
    std::vector<MenuItem>::iterator curIterator_;
    std::vector<MenuItem> menuItems_;
};

struct LunchMenuIterator: public MenuItemIterator{
    LunchMenuIterator( std::unordered_map<MenuItem, bool> const& menuItems) : menuItems_(menuItems){
        curIterator_ = menuItems_.begin();
        iterateToNextTrueItem();
    }
    bool hasNext() override{
        iterateToNextTrueItem();
        if(curIterator_ == menuItems_.end())
            return false;
        else
            return true;
    }
    void next() override{
        curIterator_ = ++curIterator_;
        iterateToNextTrueItem();
    }
    MenuItem getMenuItem() override{
        iterateToNextTrueItem();
        return curIterator_->first;
    }
private:
    void iterateToNextTrueItem(){
        while(curIterator_!=menuItems_.end() && curIterator_->second == false)
            curIterator_ = ++curIterator_;
    }
    std::unordered_map<MenuItem, bool>::iterator curIterator_;
    std::unordered_map<MenuItem, bool> menuItems_;
};


struct BreakfastMenu{
    BreakfastMenu(){
        addItem("egg",2);
        addItem("hashBrown", 1);
    }
    void addItem(std::string const& name, double price){
        menuItems_.push_back(MenuItem(name, price));
    }
    std::shared_ptr<MenuItemIterator> createIterator(){
        return std::make_shared<BreakfastMenuIterator>(menuItems_);
    }
private:
    std::vector<MenuItem> menuItems_;
};

struct LunchMenu{
    LunchMenu(){
        addItem("rice",2, true);
        addItem("bao", 1, false);
        addItem("lamb", 5, true);
    }
    void addItem(std::string const& name, double price, bool display){
        menuItems_[MenuItem(name, price)] = display;
    }
    std::shared_ptr<MenuItemIterator> createIterator(){
        return std::make_shared<LunchMenuIterator>(menuItems_);
    }
private:
    std::unordered_map<MenuItem,bool> menuItems_;
};

struct Waitress{
    Waitress(BreakfastMenu const& breakfastMenu, LunchMenu const& lunchMenu):breakfastMenu_(breakfastMenu), lunchMenu_(lunchMenu){};
    void printMenu(){
        auto breakIt = breakfastMenu_.createIterator();
        std::cout<<"Print breakfast Menu"<<std::endl;
        printMenu(breakIt);
        auto lunchIt = lunchMenu_.createIterator();
        std::cout<<"Printing lunch Menu"<<std::endl;
        printMenu(lunchIt);
    }
private:
    //without this pattern, we need two different printMenu function as std::vector and map needs to be handled differently
    void printMenu(std::shared_ptr<MenuItemIterator> mIt){
        while(mIt->hasNext()){
            mIt->getMenuItem().printItem();
            mIt->next();
        }
    }
    BreakfastMenu breakfastMenu_;
    LunchMenu lunchMenu_;
};

#endif //DESIGN_PATTERN_15_ITERATOR_PATTERN_H
