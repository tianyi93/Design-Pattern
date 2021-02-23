//
// Created by Tianyi Zhang on 2/22/21.
//

#include "15.iterator_pattern.h"
int main(){
    BreakfastMenu breakfastMenu;
    LunchMenu lunchMenu;
    Waitress waitress(breakfastMenu, lunchMenu);
    waitress.printMenu();
    return 0;
}