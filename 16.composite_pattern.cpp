//
// Created by Tianyi Zhang on 3/4/21.
//

#include "16.composite_pattern.h"
int main(){
    //breakfast Menu
    MenuComponent breakfastMenu("breakfast Menu");
    MenuComponent egg("egg", 2);
    MenuComponent hashBrown("hashBrown", 1);
    breakfastMenu.add(egg);
    breakfastMenu.add(hashBrown);

    //dinner menu contains desert menu
    MenuComponent dinnerMenu("dinner Menu");
    MenuComponent desertMenu("desert Menu", -1);
    MenuComponent iceCream("iceCream", 1);
    desertMenu.add(iceCream);
    MenuComponent rice("rice", 2);
    MenuComponent bao("bao", 1);
    dinnerMenu.add(rice);
    dinnerMenu.add(bao);
    dinnerMenu.add(desertMenu);

    //construct a allMenu to Waitress
    MenuComponent allMenu("All Menu");
    allMenu.add(breakfastMenu);
    allMenu.add(dinnerMenu);
    Waitress waitress(allMenu);
    waitress.printMenu();
}