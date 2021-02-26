//
// Created by Tianyi Zhang on 2/24/21.
//

#include "15.iterator_pattern_2.h"
int main(){
    BreakfastMenu breakfastMenu;
    Waitress waitress;
    waitress.addMenu(breakfastMenu);
    LunchMenu lunchMenu;
    waitress.addMenu(lunchMenu);
    waitress.printMenu();
    return 0;
}