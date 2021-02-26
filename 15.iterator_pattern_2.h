//
// Created by Tianyi Zhang on 2/24/21.
//

#ifndef DESIGN_PATTERN_15_ITERATOR_PATTERN_2_H
#define DESIGN_PATTERN_15_ITERATOR_PATTERN_2_H
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
    void printItem() const{
        std::cout<<name_<<","<<price_<<std::endl;
    }
    bool operator==(const MenuItem& other) const{
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


struct BreakfastMenu{
    struct Iterator{
        Iterator() = default;
        Iterator(std::vector<MenuItem>::iterator it):curIterator_(it){};
        Iterator& operator++(){
            curIterator_++;
            return *this;
        }
        bool operator==(Iterator const& rhs){
            return rhs.curIterator_ == curIterator_;
        }
        bool operator!=(Iterator const& rhs){
            return !(*this==rhs);
        }
        MenuItem const* operator->(){
            return &(*curIterator_);
        }
    private:
        std::vector<MenuItem>::iterator curIterator_;
    };

    BreakfastMenu(){
        addItem("egg",2);
        addItem("hashBrown", 1);
        begin_ = Iterator(menuItems_.begin());
        end_ = Iterator(menuItems_.end());
    }
    Iterator begin(){
        return begin_;
    }
    Iterator end(){
        return end_;
    }
private:
    void addItem(std::string const& name, double price) {
        menuItems_.push_back(MenuItem(name, price));
    }
    std::vector<MenuItem> menuItems_;
    Iterator begin_;
    Iterator end_;
};

//do not care about true of false in map, demo on how to make map and vector work on same Iterator pattern
struct LunchMenu{
    struct Iterator{
        Iterator() = default;
        Iterator(std::unordered_map<MenuItem,bool>::iterator it):curIterator_(it){};
        Iterator& operator++(){
            curIterator_++;
            return *this;
        }
        bool operator==(Iterator const& rhs){
            return rhs.curIterator_ == curIterator_;
        }
        bool operator!=(Iterator const& rhs){
            return !(*this==rhs);
        }
        MenuItem const* operator->(){
            return &(*curIterator_).first;
        }
    private:
        std::unordered_map<MenuItem,bool>::iterator curIterator_;
    };

    LunchMenu(){
        addItem("rice",2);
        addItem("bao", 1);
        addItem("lamb", 5);
        begin_ = Iterator(menuItems_.begin());
        end_ = Iterator(menuItems_.end());
    }
    Iterator begin(){
        return begin_;
    }
    Iterator end(){
        return end_;
    }
private:
    void addItem(std::string const& name, double price){
        menuItems_[MenuItem(name, price)] = true;
    }
    std::unordered_map<MenuItem,bool> menuItems_;
    Iterator begin_;
    Iterator end_;
};

struct Waitress{
    void addMenu(BreakfastMenu const& breakfastMenu) {
        breakfastMenu_ = breakfastMenu;
    }
    void addMenu(LunchMenu const& lunchMenu) {
        lunchMenu_ = lunchMenu;
    }
    void printMenu(){
        std::cout<<"Print breakfast Menu"<<std::endl;
        printMenu(breakfastMenu_);
        std::cout<<"Print lunch Menu"<<std::endl;
        printMenu(lunchMenu_);
    }
private:
    template<typename T>
    void printMenu(T menu){
        for(auto it = menu.begin(); it!=menu.end(); ++it){
            it->printItem();
        }
    }
    BreakfastMenu breakfastMenu_;
    LunchMenu lunchMenu_;
};
#endif //DESIGN_PATTERN_15_ITERATOR_PATTERN_2_H
