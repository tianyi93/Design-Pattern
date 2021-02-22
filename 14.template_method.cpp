//
// Created by Tianyi Zhang on 2/21/21.
//

#include "14.template_method.h"
int main(){
    Tea tea;
    Coffee coffee;
    std::cout<<"prepare tea"<<std::endl;
    tea.prepareRecipe();
    std::cout<<"prepare coffee"<<std::endl;
    coffee.prepareRecipe();
    return 0;
}