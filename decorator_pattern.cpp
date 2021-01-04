//
// Created by Tianyi Zhang on 1/3/21.
//

#include "decorator_pattern.h"
#include <iostream>
int main(){
    std::shared_ptr<Beverage> houseBlend = std::make_shared<HouseBlend>();
    houseBlend = std::make_shared<Mocha>(houseBlend);
    houseBlend = std::make_shared<Milk>(houseBlend);
    std::cout<<"description : "<<houseBlend->getDescription()<<", price: "<<houseBlend->cost()<<std::endl;

    std::shared_ptr<Beverage> darkRoast = std::make_shared<DarkRoast>();
    darkRoast = std::make_shared<Milk>(darkRoast);
    darkRoast = std::make_shared<Milk>(darkRoast);
    std::cout<<"description : "<<darkRoast->getDescription()<<", price: "<<darkRoast->cost()<<std::endl;

    return 0;
}