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
        Iterator(std::vector<MenuItem>* menuItems):menuItems_(menuItems), pos_(0){};
        Iterator& operator++(){
            pos_++;
            return *this;
        }
        bool operator==(Iterator const& rhs){
            return rhs.pos_ == pos_;
        }
        bool operator!=(Iterator const& rhs){
            return !(*this==rhs);
        }
        MenuItem const* operator->(){
            return &(*menuItems_)[pos_];
        }
        Iterator begin(){
            this->pos_ = 0;
            return *this;
        }
        Iterator end(){
            this->pos_ = menuItems_->size();
            return *this;
        }
    private:
        std::vector<MenuItem>* menuItems_;
        int pos_;
    };

    BreakfastMenu(){
        addItem("egg",2);
        addItem("hashBrown", 1);
    }
    Iterator begin(){
        return Iterator(&menuItems_).begin();
    }
    Iterator end(){
        return Iterator(&menuItems_).end();
    }
private:
    void addItem(std::string const& name, double price) {
        menuItems_.push_back(MenuItem(name, price));
    }
    std::vector<MenuItem> menuItems_;
};

struct LunchMenu{
    struct Iterator{
        Iterator() = default;
        Iterator(std::unordered_map<MenuItem,bool>* menuItems):menuItems_(menuItems), curIterator_(menuItems_->begin()){};
        Iterator& operator++(){
            ++curIterator_;
            while(curIterator_ != menuItems_->end() && curIterator_->second == false)
                ++curIterator_;
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
        Iterator begin(){
            for(auto it = menuItems_->begin(); it!= menuItems_->end(); it++) {
                if(it->second == true) {
                    curIterator_ = it;
                    break;
                }
            }
            return *this;
        }
        Iterator end(){
            curIterator_ = menuItems_->end();
            return *this;
        }
    private:
        std::unordered_map<MenuItem,bool>::iterator curIterator_;
        std::unordered_map<MenuItem,bool>* menuItems_;
    };

    LunchMenu(){
        addItem("rice",2, true);
        addItem("bao", 1, false);
        addItem("lamb", 5, true);
        addItem("beef", 5, false);
    }
    Iterator begin(){
        return Iterator(&menuItems_).begin();
    }
    Iterator end(){
        return Iterator(&menuItems_).end();
    }
private:
    void addItem(std::string const& name, double price, bool display){
        menuItems_[MenuItem(name, price)] = display;
    }
    std::unordered_map<MenuItem,bool> menuItems_;
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
