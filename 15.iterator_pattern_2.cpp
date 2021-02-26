//
// Created by Tianyi Zhang on 2/24/21.
//

#include "15.iterator_pattern_2.h"
int main(){
    BreakfastMenu breakfastMenu;
    Waitress waitress(breakfastMenu);
    waitress.printMenu();
    return 0;
}