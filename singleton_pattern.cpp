//
// Created by Tianyi Zhang on 11/9/20.
//

#include "singleton_pattern.h"
int main(){
    auto singleton = Singleton::getInstance("singleton instance");
    singleton->print();
    auto singleton2 = Singleton::getInstance("singleton instance2");
    singleton2->print();
    return 0;
}